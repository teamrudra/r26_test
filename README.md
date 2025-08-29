Rudra Test – Enhanced Fork (Harshil24Agrawal/r26_test)
Overview

This repository is a fork of teamrudra/r26_test.
The original project aimed to decode GPS data (UBX format), implement a grid-based path planner, and generate odometry commands for a rover. In my fork, I've refined and extended it to include a modular and reusable Odometry component, improving clarity and functionality.

Original Repository Features (teamrudra/r26_test)

Task 1 – GPS Data Decoding: Read and correct latitude/longitude from u-blox UBX format.

Task 2 – Path Planner: Implement a grid-based algorithm to find an optimal path from start to goal on a defined map.

Task 3 – Odometry Command Generation: Convert the planned path into motion commands (e.g., rotation angle and traversal time) based on rover wheel parameters.

Task 4 – Build & Verification: Ensure the project compiles and runs using provided Makefile.

Project Layout:

src/main.cpp – Main test runner

src/ublox_reader.cpp – UBX parsing logic

src/planning.cpp – Planner::pathplanning implementation

src/odometry.cpp – Odometry::computeCommands implementation

Build via make build; verify with make check

GitHub

Enhancements in My Fork

In Harshil24Agrawal/r26_test, I've introduced significant improvements for clarity and modular design:

1. Odometry Module Refactor (lib/odometry.h)

Encapsulates odometry logic in a standalone Odometry class.

Supports configuration of wheel radius and wheel RPM parameters.

Offers methods to compute:

Total angle rotation along the path.

Total traversal time based on wheel dynamics.

Distance and angle calculations between waypoints.

2. Improved Structure & Usability

Organized odometry-related code into lib/, separating it from core path planning and GPS parsing logic.

Promotes reuse and clarity when integrating into higher-level applications.

Usage Guide
Building the Project
git clone https://github.com/Harshil24Agrawal/r26_test.git
cd r26_test
make build

Running Checks
make check


Ensures that both planner and odometry components work as expected.

Example Integration
#include "lib/odometry.h"

// Configure rover parameters
double wheel_radius = 0.1;  // meters
double wheel_rpm    = 60.0; // rotations per minute

Odometry odo(wheel_radius, wheel_rpm);

std::vector<Coordinate> path = /* path generated from Planner */;
MotionCommand cmd = odo.computeCommands(path);

std::cout << "Total rotation: " << cmd.angle_deg << " degrees\n";
std::cout << "Traversal time: " << cmd.time_sec << " seconds\n";

MotionCommand Structure

Returned by computeCommands(path), includes:

angle_deg → Total rotation (in degrees) the rover must execute.

time_sec → Total traversal time (in seconds) based on wheel specs.

Why This Fork Stands Out

Modularity: Odometry computation is encapsulated, making it easier to test, extend, or reuse.

Configurability: Wheel parameters are customizable without altering internal logic.

Maintainability: Clear separation of concerns between GPS parsing, planning, and motion computation.
