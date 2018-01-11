/*
 * lc_694_Number_of_Distinct_Islands.cpp
 *
 *  Created on: Jan 10, 2018
 *      Author: HenryWu2016@gmail.com
 */

#include "pnsei.hpp"

namespace lc_694_Number_of_Distinct_Islands {

class Solution {
public:
  // T: O(*), S: O(*)
  int numDistinctIslands(vector<vector<int>>& grid) {
    int r = 0;
    if (grid.empty() or grid[0].empty())
      return 0;
    vector<pair<int, int>> dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    int R = grid.size(), C = grid[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C));
    set<vector<pair<int, int>>> svi;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (visited[i][j] or grid[i][j] == 0)
          continue;
        visited[i][j] = true; ////
        queue<pair<int, int>> q;
        q.push( { i, j });
        vector<pair<int, int>> ids(1, { i, j });
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
                if (grid[nx][ny] == 1)
                  q.push( { nx, ny }), ids.back_back({nx, ny});
              }
            }
          }
        } // graph traversal complete
        sort(ids.begin(), ids.end());
        auto tmp = ids.front();
        for (auto& i : ids)
          i.first -= tmp.first, i.second -= tmp.second;
        svi.insert(ids);
      }
    }
    return svi.size();
  }
};

TEST(lc_694_Number_of_Distinct_Islands_C1, lc_694_Number_of_Distinct_Islands_T) {
  Solution sln;
  vector<vector<int>> vvc = { { 1, 1, 1, 1, 0 }, { 1, 1, 0, 1, 0 }, { 1, 1, 0,
      0, 0 }, { 0, 0, 0, 0, 0 } };
  ASSERT_EQ(sln.numDistinctIslands(vvc), 1);

  // edge case 1
  /*
   * [
   [1,1,1,1],
   [1,0,1,0],
   [0,0,0,0],
   [0,1,1,1],
   [1,1,0,1]]
   * */
  vvc= { {1,1,1,1}, {1,0,1,0}, {0,0,0,0}, {0,1,1,1}, {1,1,0,1}};
  EXPECT_EQ(sln.numDistinctIslands(vvc), 2);
}

}
