#include "odometry.h"
#include <cmath>
#include <ctime>
#include <iterator>
#include <numeric>

using namespace std;
double wheel_distance;
double rps;//creating gloabally instead of locally
Odometry::Odometry(double wheel_radius, double rpm)
    : radius(wheel_radius), rpm(rpm) {
  // Linear velocity (m/s) =(wheel circumference * revolutions per second)
   rps = rpm / 60.0;
  linear_vel = 2 * M_PI * radius * rps;
}

double Odometry::distance(int x1, int y1, int x2, int y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
  wheel_distance=((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));//also storing the distance traversed to calc angle_traversed
}

double Odometry::angle(int x1, int y1, int x2, int y2) {
  // atan2 returns radians, convert to degrees
  return atan2(y2 - y1, x2 - x1) * 180.0 / M_PI;
}

MotionCommand Odometry::computeCommands(vector<pair<int, int>> &path) {

  MotionCommand res = {0.0, 0.0};
   
  // store total time and angle traversed
 /* Implement you odometry logic here */
 double circumference = 2 * M_PI * radius;
 double revolutions = wheel_distance/ circumference;
  res.angle_deg = revolutions * 2 * M_PI; 
  res.time_sec = revolutions / rps; 
  

  return res;
}
