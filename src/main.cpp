#include "main.hpp"

float ax, ay, az, gx, gy, gz, mx, my, mz, depth;
void setup() {
  initializeCommunication();
  initializeIMU();
  initializeDepthSensor();
  initializeThrusters();
}

void loop() {
  updateIMUReadings(ax, ay, az, gx, gy, gz, mx, my, mz);
  updateDepthSensorReadings(depth);
  sendIMUReadings(ax, ay, az, gx, gy, gz, mx, my, mz);
  sendDepth(depth);
  checkForCommands();
}
