/*
 * lc_259_3Sum_Smaller.cpp
 *
 *  Created on: Jan 10, 2018
 *      Author: HenryWu2016@gmail.com
 */

#include "pnsei.hpp"

namespace lc_259_3Sum_Smaller {

class Solution {
public:
  // T: O(N^2), S: O(*)
  int threeSumSmaller(vector<int>& nums, int target) {
    int r = 0, L = nums.size(), j, k, sum;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < L - 2; ++i) {
      j = i + 1, k = L - 1;
      while (j < k) {
        sum = nums[i] + nums[j] + nums[k];
        if (sum < target) {
          r += k - j;
          j++;
        } else if (sum >= target)
          k--;
      }
    }
    return r;
  }
};

TEST(lc_259_3Sum_Smaller_case1, lc_259_3Sum_Smaller_test) {
  Solution sln;
  vector<int> vi = { 3, 1, 0, -2 };
  int r = sln.threeSumSmaller(vi, 4);
  ASSERT_EQ(r, 3);
}

}
