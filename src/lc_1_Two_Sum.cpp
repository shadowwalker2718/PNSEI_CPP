/*
 * lc_1_Two_Sum.hpp
 *
 *  Created on: Jan 10, 2018
 *      Author: HenryWu2016@gmail.com
 */

#ifndef LC_1_TWO_SUM_CPP_
#define LC_1_TWO_SUM_CPP_

#include "pnsei.hpp"

namespace lc_1_Two_Sum {

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> v2i;
    for (int i = 0; i < nums.size(); ++i) {
      int t = target - nums[i];
      if (v2i.count(t)) {
        return {i, v2i[t]};
      }
      v2i[nums[i]] = i;
    }
    return {};
  }
};

void test() {
  Solution sln;

}

}

#endif /* LC_1_TWO_SUM_CPP_ */
