/*
 * lc_15_3Sum.hpp
 *
 *  Created on: Jan 10, 2018
 *      Author: HenryWu2016@gmail.com
 */

#ifndef LC_15_3SUM_CPP_
#define LC_15_3SUM_CPP_

#include "pnsei.hpp"

namespace lc_15_3Sum {

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> r;
    if (nums.size() < 3)
      return r;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 and nums[i] == nums[i - 1])
        continue;
      int j = i + 1, k = nums.size() - 1;
      while (j < k) {
        if (nums[i] + nums[j] == -nums[k]) {
          r.push_back( { nums[i], nums[j], nums[k] });
          while (++j < k and nums[j] == nums[j - 1])
            ;
          while (j < --k and nums[k] == nums[k + 1])
            ;
        } else if (nums[i] + nums[j] < -nums[k])
          j++;
        else
          k--;
      }
    }
    return r;
  }
};

TEST(lc_15_3Sum_case1, lc_15_3Sum) {
  Solution sln;
  vector<int> vi = { -1, 0, 1, 2, -1, -4 };
  auto r = sln.threeSum(vi);
  ASSERT_EQ(r.size(), 2);
}

}

#endif /* LC_15_3SUM_CPP_ */
