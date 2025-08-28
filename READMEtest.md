# r26_test Submission

## Solution
The task involved two main problems: 
1. **Path Planning** – Compute a valid path from a start to a goal position on a 2D grid while avoiding obstacles.
2. **Odometry** – Compute motion commands (time to traverse and total rotation) for a robot along the planned path using wheel radius and RPM.

## Thought Process
- First, I analyzed the problem and split it into **path planning** and **odometry**.  
- For path planning, I decided on a **4-connected A* algorithm** using Euclidean distance as a heuristic.  
- For odometry, I computed **linear velocity** from wheel radius and RPM, then calculated **distance and heading changes** between consecutive points.  
- I ensured angle changes were wrapped between -180° and 180° to correctly sum rotations.

## Implementation
- Created `Planner` class for path planning and `Odometry` class for motion commands.  
- Used vectors and pairs to store paths and positions.  
- Tested the implementation on example grids and start/goal positions, verified outputs manually.  
- Handled minor compile issues such as `M_PI` by defining pi as 3.141592653589793.  

## Challenges
- Angle wrapping in odometry required careful handling to avoid incorrect rotation sums.  
- Path reconstruction in A* needed careful indexing to reverse the path correctly.  
- Initially faced compile issues on Windows due to `M_PI` not being defined.

## Resources Used
- C++ documentation for `atan2`, `sqrt`, `vector`.  
- GitHub Docs for creating Pull Requests.  
- AI assistance to understand odometry formulas and path planning structure.  
- Online references for A* algorithm and grid representation.
