/*
 * lc_392_Is_Subsequence.cpp
 *
 *  Created on: Jan 11, 2018
 *      Author: HenryWu2016@gmail.com
 */

#include "pnsei.hpp"

namespace  lc_392_Is_Subsequence{

class Solution {
public:
    // T: O(M+N), S: O(*)
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        while(i<s.size()){
          while(j<t.size()){
            if(s[i]==t[j]){
              j++; break;
            }
            j++;
          }
          if(s[i]!=t[j-1]) ////
            return false;
          i++;
        }
        return i==s.size();
    }
};

TEST(lc_392_Is_Subsequence_C1, lc_392_Is_Subsequence_T){
    Solution sln;
    string s = "axc", t = "ahbgdc";
    ASSERT_EQ(sln.isSubsequence(s,t), false);
    s = "abc", t = "ahbgdc";
    ASSERT_EQ(sln.isSubsequence(s,t), true);
}

}
