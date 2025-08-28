#include "odometry.h"
#include <cmath>
#include <ctime>
#include <iterator>
#include <numeric>

using namespace std;

Odometry::Odometry(double wheel_radius, double rpm)
    : radius(wheel_radius), rpm(rpm) {
  // Linear velocity (m/s) =(wheel circumference * revolutions per second)
  double rps = rpm / 60.0;
  linear_vel = 2 *3.14159265358979323846
* radius * rps;
}

double Odometry::distance(int x1, int y1, int x2, int y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double Odometry::angle(int x1, int y1, int x2, int y2) {
  // atan2 returns radians, convert to degrees
  return atan2(y2 - y1, x2 - x1) * 180.0 / 3.14159265358979323846
;
}

MotionCommand Odometry::computeCommands(vector<pair<int, int>> &path) {

  MotionCommand res = {0.0, 0.0}; // store total time and angle traversed

 /* Implement you odometry logic here */
  if (path.size() < 2) return res;

  double prev_heading = angle(path[0].first, path[0].second,
                              path[1].first, path[1].second);

  for (size_t i = 1; i < path.size(); i++) {
    // distance between consecutive points
    double dist = distance(path[i-1].first, path[i-1].second,
                           path[i].first, path[i].second);
    res.time_sec += dist / linear_vel;

    // current heading
    double heading = angle(path[i-1].first, path[i-1].second,
                           path[i].first, path[i].second);

    // change in heading
    double dtheta = heading - prev_heading;
    while (dtheta > 180.0) dtheta -= 360.0;
    while (dtheta < -180.0) dtheta += 360.0;

    res.angle_deg += fabs(dtheta);
    prev_heading = heading;
  }

  return res;
}
