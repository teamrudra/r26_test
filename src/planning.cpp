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
  if (!isvalid(start.first, start.second) || !isvalid(goal.first, goal.second))
    return path;

  // movement directions (4-connected grid)
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};

  vector<vector<double>> gscore(rows, vector<double>(cols, 1e9));
  vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));

  struct Node { int x, y; double f, g; };
  vector<Node> open;

  int sx = start.first, sy = start.second;
  int gx = goal.first, gy = goal.second;

  gscore[sx][sy] = 0.0;
  open.push_back({sx, sy, heuristic(sx, sy, gx, gy), 0.0});

  while (!open.empty()) {
    // find node with smallest f
    int best_idx = 0;
    for (int i = 1; i < (int)open.size(); i++) {
      if (open[i].f < open[best_idx].f)
        best_idx = i;
    }
    Node cur = open[best_idx];
    open.erase(open.begin() + best_idx);

    if (cur.x == gx && cur.y == gy) {
      // reconstruct path backwards
      int cx = gx, cy = gy;
      vector<pair<int, int>> revpath;
      while (!(cx == sx && cy == sy)) {
        revpath.push_back({cx, cy});
        auto p = parent[cx][cy];
        cx = p.first;
        cy = p.second;
      }
      revpath.push_back({sx, sy});
      // reverse manually
      for (int i = (int)revpath.size() - 1; i >= 0; i--)
        path.push_back(revpath[i]);
      return path;
    }

    for (int k = 0; k < 4; k++) {
      int nx = cur.x + dx[k];
      int ny = cur.y + dy[k];

      if (!isvalid(nx, ny)) continue;

      double tentative_g = gscore[cur.x][cur.y] + 1.0;
      if (tentative_g < gscore[nx][ny]) {
        gscore[nx][ny] = tentative_g;
        parent[nx][ny] = {cur.x, cur.y};
        double f = tentative_g + heuristic(nx, ny, gx, gy);
        open.push_back({nx, ny, f, tentative_g});
      }
    }
  }

  return path;
}
