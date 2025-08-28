#include "planning.h"
#include <cmath>
#include <vector>

using namespace std;

Planner::Planner(const vector<vector<bool>> &grid) : grid(grid) {
  rows = grid.size();
  cols = grid[0].size();
}

bool Planner::isvalid(int x, int y) const {
  return (x >= 0 && x < rows && y >= 0 && y < cols && !grid[x][y]);
}

double Planner::heuristic(int x1, int y1, int x2, int y2) const {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

vector<pair<int, int>> Planner::pathplanning(pair<int, int> start,
                                             pair<int, int> goal) {
  vector<pair<int, int>> path; // store final path 
			       
  /* Implement Path Planning logic here */
      
  /* 
     Mine Own:-
     1.Considering the path as a grid and diving like excell sheet
     2.Taking the sarting pos as start cell and ending pos as goal cell
     3.So the path can be clear or with obstacle.Clear path will be 1 full cell and blocked will be 1 full cell
     4.So from a start the obj can move either in up,down,left or right 
     4.If it encounterd obstacle cell it will not cross it but will take another path or cell
     5.Running this test randomly for good amt of time to get various path using regression model or appropriate ml model
     6.the path with least distance can be taken as final path

     From wht I understood from the internet:-
     1.Instead of running on multiple paths,we estimate how far is the goal with help of heuristic
     2.combining the actual cdis+estimated distance to get fx
     3.using priority queue which will pick the cell with lowest fx
     4.Stoppingon reaching the goal
     5.thus the path will be created 

      Diff:
     1.Training a modle can take a lot of time to stand on foot from ground bottom
     2.Using estimation will give more accurate
     3.ML will depend on estimators so accuracy willl depend on solely how much time we will give but still wont be able to tell whether after all that time we will still get a good score
    */

  return path;
}
