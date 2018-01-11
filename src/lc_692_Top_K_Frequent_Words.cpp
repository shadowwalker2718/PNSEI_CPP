/*
 * lc_692_Top_K_Frequent_Words.cpp
 *
 *  Created on: Jan 10, 2018
 *      Author: HenryWu2016@gmail.com
 */

#include "pnsei.hpp"

namespace lc_692_Top_K_Frequent_Words {

class Solution {
public:
	// T: O(N*LogK), S: O(N)
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int> m;
		for (auto s : words)
			m[s]++;
		auto comp =
				[](pair<string,int>& p1, pair<string,int>& p2) {
					return (p1.second > p2.second) ||
							(p1.second == p2.second && p1.first < p2.first);
				};
		priority_queue<pair<string, int>, vector<pair<string, int>>,
				decltype(comp)> pq(comp);
		int i = 0;
		for (auto pr : m) {
			pq.push(pr);
			if (++i > k)
				pq.pop();
		}
		vector<string> r;
		while (!pq.empty())
			r.push_back(pq.top().first), pq.pop();
		reverse(r.begin(), r.end());
		return r;
	}
};

TEST(lc_692_Top_K_Frequent_Words_C1, lc_692_Top_K_Frequent_Words_T) {
	Solution sln;
	vector<string> vi = { "i", "love", "code", "i", "love", "coding" };
	auto r = sln.topKFrequent(vi, 2);
	ASSERT_EQ(r[0], "i");
	ASSERT_EQ(r[2], "love");
}

}
