/*
 * lc_305_Number_of_Islands_II.cpp
 *
 *  Created on: Jan 10, 2018
 *      Author: HenryWu2016@gmail.com
 */

#include "pnsei.hpp"

namespace lc_305_Number_of_Islands_II {

class Solution {
public:
  // T: O(K*LogMN), S: O(*)
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> res;
    roots = vector<int>(m * n, -1);
    vector<pair<int, int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    int island = 0;
    for (auto pos : positions) {
      int x = pos.first, y = pos.second, idx_p = x * n + y;
      roots[idx_p] = idx_p;
      ++island;
      for (auto dir : dirs) {
        int row = x + dir.first, col = y + dir.second, idx_new = row * n + col;
        if (row >= 0 && row < m && col >= 0 && col < n
            && roots[idx_new] != -1) {
          int rootNew = findRoot(idx_new), rootPos = findRoot(idx_p);
          if (rootPos != rootNew)
            roots[rootPos] = rootNew, --island;
        }
      }
      res.push_back(island);
    }
    return res;
  }
private:
  vector<int> roots;
  int findRoot(int idx) {
    if (idx != roots[idx])
      roots[idx] = findRoot(roots[idx]);
    return roots[idx];
  }
};

TEST(lc_305_Number_of_Islands_II_C1, lc_305_Number_of_Islands_II_T) {
  Solution sln;
  //ASSERT_EQ(r.size(), 2);
}

}
