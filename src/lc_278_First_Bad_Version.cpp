/*
 * lc_278_First_Bad_Version.cpp
 *
 *  Created on: Jan 12, 2018
 *      Author: HenryWu2016@gmail.com
 */

#include "pnsei.hpp"

namespace lc_278_First_Bad_Version {

bool isBadVersion(int version) {
  return version > 10;
}

class Solution {
public:
  // T: O(logN), S: O(*)
  //lower_bound of bad versions
  int firstBadVersion(int n) {
    int h = 1, t = n;
    while (h <= t) {
      int m = h + (t - h) / 2;
      if (isBadVersion(m)) {
        t = m - 1;
      } else
        h = m + 1;
    }
    return h <= n ? h : -1;
  }
};

TEST(lc_278_First_Bad_Version_C1, lc_278_First_Bad_Version_T) {
  Solution sln;
  ASSERT_EQ(sln.firstBadVersion(100), 11);
}

}
