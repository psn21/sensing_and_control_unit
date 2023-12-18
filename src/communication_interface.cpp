#include "communication_interface.hpp"
#include "thruster_interface.hpp"
#include "config.hpp"

ros::NodeHandle nh;

sensing_control_msgs::CustomDepthMsg depth_data;
sensing_control_msgs::CustomIMUMsg imu_data;
std_msgs::Int8MultiArray throttle;

ros::Subscriber <std_msgs::Int8MultiArray> sub("pwm_values", &throttleCb);
ros::Publisher depth_pub("depth_data", &depth_data);
ros::Publisher imu_pub("imu_data", &imu_data);

void initializeCommunication() {
    nh.initNode();
    nh.subscribe(sub);
    nh.advertise(depth_pub);
    nh.advertise(imu_pub);
}


void sendDepth(float depth) {
    depth_data.depth = depth;
    depth_pub.publish(&depth_data);
}

void sendIMUReadings(float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz) {
    imu_data.acceleration[0] = ax;
    imu_data.acceleration[1] = ay;
    imu_data.acceleration[2] = az;

    imu_data.gyroscope[0] = gx;
    imu_data.gyroscope[1] = gy;
    imu_data.gyroscope[2] = gz;

    imu_data.magnetometer[0] = mx;
    imu_data.magnetometer[1] = my;
    imu_data.magnetometer[2] = mz;

    imu_pub.publish(&imu_data);
}

void throttleCb(const std_msgs::Int8MultiArray& pwm_msg){
    int8_t pwm_values[NUMBER_OF_THRUSTERS];
    for (int thruster_index = 0; thruster_index < NUMBER_OF_THRUSTERS; thruster_index ++)
    {
        pwm_values[thruster_index] = pwm_msg.data[thruster_index];
    }
    setThrusterThrottle(pwm_values);
}

void checkForCommands(){
    nh.spinOnce();
}
