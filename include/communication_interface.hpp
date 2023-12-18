#ifndef COMMUNICATION_INTERFACE_HPP
#define COMMUNICATION_INTERFACE_HPP
#include "ros_lib/sensing_control_msgs/CustomDepthMsg.h"
#include "ros_lib/sensing_control_msgs/CustomIMUMsg.h"

#include<Arduino.h>
#include <ros.h>
#include <std_msgs/Int8MultiArray.h>

extern ros::NodeHandle nh;

extern sensing_control_msgs::CustomDepthMsg depth_data;
extern sensing_control_msgs::CustomIMUMsg imu_data;

extern ros::Publisher depth_pub;
extern ros::Publisher imu_pub;

void initializeCommunication();
void sendDepth(float depth);
void sendIMUReadings(float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz);
void throttleCb(const std_msgs::Int8MultiArray& pwm_msg);
void checkForCommands();
#endif // COMMUNICATION_INTERFACE_HPP