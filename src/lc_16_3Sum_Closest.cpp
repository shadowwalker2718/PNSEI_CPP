/*
 * lc_16_3Sum_Closest.hpp
 *
 *  Created on: Jan 10, 2018
 *      Author: HenryWu2016@gmail.com
 */

#ifndef LC_16_3SUM_CLOSEST_CPP_
#define LC_16_3SUM_CLOSEST_CPP_

#include "pnsei.hpp"

namespace lc_16_3Sum_Closest {

class Solution {
public:
  // T: O(N^2), S: O(*)
  int threeSumClosest(vector<int>& nums, int target) {
    int d = INT_MAX, r;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
      int j = i + 1, k = nums.size() - 1;
      while (j < k) {
        int t = nums[i] + nums[j] + nums[k];
        if (d > abs(t - target))
          d = abs(t - target), r = t;
        if (t < target)
          j++;
        else if (t == target)
          return t;
        else
          k--;
      }
    }
    return r;
  }
};

void test() {
  Solution sln;
  assert(1);
}

}

#endif /* LC_16_3SUM_CLOSEST_CPP_ */
