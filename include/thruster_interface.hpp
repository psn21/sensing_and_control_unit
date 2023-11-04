#ifndef THRUSTER_INTERFACE_HPP
#define THRUSTER_INTERFACE_HPP
#include <Arduino.h>
inline void initializeThrusters();
inline void setThrusterSpeeds(std::vector<int16_t> speeds);
#endif // THRUSTER_INTERFACE_HPP