/*
 * lc_611_Valid_Triangle_Number.cpp
 *
 *  Created on: Jan 10, 2018
 *      Author: HenryWu2016@gmail.com
 */

#include "pnsei.hpp"

namespace lc_611_Valid_Triangle_Number {

class Solution {
public:
  // T: O(N^3), S: O(*)
  int triangleNumber_Naive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int r = 0, L = nums.size();
    if (L < 3)
      return r;
    for (int i = 0; i < L - 2; ++i) {
      for (int j = i + 1; j < L - 1; ++j) {
        for (int k = j + 1; k < L; ++k)
          if (nums[i] + nums[j] > nums[k])
            r++;
      }
    }
    return r;
  }

  // T: O(N^2), S: O(*)
  int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int r = 0, L = nums.size();
    if (L < 3)
      return r;
    for (int i = 0; i < L - 2; ++i) {
      for (int j = i + 1, k = j + 1; j < L - 1; ++j) {
        while (k < L && nums[i] + nums[j] > nums[k])
          k++;
        if (k > j)
          r += k - j - 1;
      }
    }
    return r;
  }
};

TEST(lc_611_Valid_Triangle_Number_C1, lc_611_Valid_Triangle_Number_T) {
  Solution sln;
  vector<int> vi = { 1, 1, 0, 0 };
  int r = sln.triangleNumber(vi);
  ASSERT_EQ(r, 0);
}

}
