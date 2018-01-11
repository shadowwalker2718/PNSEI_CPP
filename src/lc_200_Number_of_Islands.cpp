/*
 * lc_200_Number_of_Islands.cpp
 *
 *  Created on: Jan 10, 2018
 *      Author: HenryWu2016@gmail.com
 */

#include "pnsei.hpp"

namespace lc_200_Number_of_Islands {

#define BFS_ITERATIVE

class Solution {
public:

#ifdef BFS_ITERATIVE
  // T: O(*), S: O(*)
  // BFS
  int numIslands(vector<vector<char>>& grid) {
    int r = 0;
    if (grid.empty() or grid[0].empty())
      return 0;
    vector<pair<int, int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    int R = grid.size(), C = grid[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C));
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (visited[i][j] or grid[i][j] == '0')
          continue;
        visited[i][j] = true; ////
        queue<pair<int, int>> q;
        q.push( { i, j });
        while (!q.empty()) {
          int sz = q.size();
          while (sz--) {
            auto t = q.front();
            q.pop();
            for (auto d : dir) {
              int nx = t.first + d.first, ny = t.second + d.second;
              if (nx >= 0 and nx < R and ny >= 0 and ny < C
                  and !visited[nx][ny]) {
                visited[nx][ny] = true; ////
                if (grid[nx][ny] == '1')
                  q.push( { nx, ny });
              }
            }
          }
        }
        r++;
      }
    }
    return r;
  }

#elif defined(DFS_ITERATIVE)

  int numIslands(vector<vector<char>>& grid) {
    int r = 0;
    if (grid.empty() || grid[0].empty()) return r;
    const vector<pair<int, int>> D = { {1,0}, {-1,0}, {0,1}, {0,-1}};
    int ROW = grid.size(), COL = grid[0].size();
    vector<vector<bool>> vd(ROW, vector<bool>(COL));
    int i = 0;
    while (i<ROW) {
      int j = 0;
      while (j<COL) {
        if (vd[i][j] || grid[i][j]=='0') {++j; continue;}
        stack<pair<int, int>> stk; ////
        stk.push( {i,j}), vd[i][j]=true;
        while (!stk.empty()) {
          auto p = stk.top(); stk.pop();
          for (auto d : D) {
            int x = p.first + d.first, y = p.second + d.second;
            if (x >= 0 && x < ROW && y >= 0 && y < COL && !vd[x][y]) {
              if (grid[x][y]=='1') stk.push( {x, y});
              vd[x][y] = true;
            }
          }
        }
        ++r, ++j;
      }
      ++i;
    }
    return r;
  }

#elif defined(UNION_FIND)

private:
  vector<int> bo;
  vector<int> sz;
  void makeset(int len) {
    bo.resize(len);
    iota(bo.begin(), bo.end(), 0); // 0,1,2,3,4...
    sz.resize(len);
    fill(sz.begin(), sz.end(), 1);
  }
  int findset(int x) {
    if (x != bo[x]) { // Be careful it is `if`
      bo[x] = findset(bo[x]);
    }
    return bo[x];
  };
  void merge(int x, int y) {
    int bo1 = findset(x), bo2 = findset(y);
    if (bo1 == bo2) {return;}
    int sma = sz[bo1] > sz[bo2] ? bo2 : bo1;
    int big = sz[bo1] > sz[bo2] ? bo1 : bo2;
    bo[sma] = big, sz[big] += sz[sma], sz[sma] = 0;
  };
public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    const vector<pair<int, int>> DIR = { {0, -1}, {-1,0}, {1,0}, {0,1}};
    const int ROW = grid.size(), COL = grid[0].size();
    makeset(ROW*COL);
    auto m2a = [COL](int x, int y) {return x*COL + y;}; ////
    for (int i = 0; i<ROW; ++i) {
      for (int j = 0; j<COL; ++j) {
        int aidx = m2a(i, j); //array index
        if (grid[i][j]=='0') {
          sz[aidx] = 0;
          continue;
        }
        for (auto d : DIR) {
          int ni = i + d.first, nj = j + d.second;
          int naidx = m2a(ni, nj);
          if (ni >= 0 && ni<ROW && nj >= 0 && nj<COL
              && grid[ni][nj]=='1'/* && aidx<naidx*/)
          {
            merge(aidx, naidx);
          }
        }
      }
    }
    return count_if(sz.cbegin(), sz.cend(), [](int i) {return i>0;});
  }

#endif

};

TEST(lc_200_Number_of_Islands_C1, lc_200_Number_of_Islands_T) {
  Solution sln;
  vector<vector<char>> vvc = { { '1', '1', '1', '1', '0' }, { '1', '1', '0',
      '1', '0' }, { '1', '1', '0', '0', '0' }, { '0', '0', '0', '0', '0' } };
  ASSERT_EQ(sln.numIslands(vvc), 1);
}

}
