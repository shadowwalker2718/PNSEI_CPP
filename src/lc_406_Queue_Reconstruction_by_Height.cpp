/*
 * lc_406_Queue_Reconstruction_by_Height.cpp
 *
 *  Created on: Jan 10, 2018
 *      Author: HenryWu2016@gmail.com
 */

#include "pnsei.hpp"

namespace lc_406_Queue_Reconstruction_by_Height {

class Solution {
public:

#if 1

  // T: O(N^2), S: O(1)
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    sort(people.begin(), people.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) {
          return a.first > b.first || (a.first == b.first && a.second < b.second);
        });
    for (int i = 1; i < people.size(); ++i) {
      int cnt = 0;
      for (int j = 0; j < i; ++j) {
        if (cnt == people[i].second) {
          pair<int, int> t = people[i];
          for (int k = i - 1; k >= j; --k)
            people[k + 1] = people[k];
          people[j] = t;
          break;
        }
        if (people[j].first >= people[i].first)
          ++cnt;
      }
    }
    return people;
  }

#elif defined(__SPACE_O_N__)

  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    sort(people.begin(), people.end(), [](const pair<int, int>& a,const pair<int, int>& b) {
          return (a.first > b.first) || ((a.first == b.first) && (a.second < b.second));
        });
    vector<pair<int, int>> r;
    for(auto p : people)
    r.insert(r.begin() + p.second, p);
    return r;
  }

#endif
};

TEST(lc_406_Queue_Reconstruction_by_Height_C1, lc_406_Queue_Reconstruction_by_Height_T) {
  Solution sln;
  vector<pair<int, int>> people = { { 7, 0 }, { 4, 4 }, { 7, 1 }, { 5, 0 }, { 6,
      1 }, { 5, 2 } };
  vector<pair<int, int>> output = { { 5, 0 }, { 7, 0 }, { 5, 2 }, { 6, 1 }, { 4,
      4 }, { 7, 1 } };
  ASSERT_EQ(sln.reconstructQueue(people), output);
}

}
