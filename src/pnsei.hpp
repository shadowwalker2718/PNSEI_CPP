/*
 * pnsei.hpp
 *
 *  Created on: Jan 8, 2018
 *      Author: HenryWu2016@gmail.com
 */

#pragma once
#ifndef PNSEI_HPP_
#define PNSEI_HPP_

// Stream
#include <iostream>
#include <fstream>
#include <sstream>

// STL
#include <vector>
#include <string>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <forward_list>
#include <algorithm>
#include <functional>
#include <tuple>
#include <deque>
#include <array>
#include <stack>
#include <queue>
#include <bitset>
#include <iterator>
#include <numeric>

#include <utility>


// Memory Management
#include <memory>

// Time
#include <chrono>

// Assert
#include <cassert>
#include <cmath>

// Exception
#include <exception>

// Multithread
#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>

// Numerics
#include <cmath>

#include <climits>

using namespace std;
using namespace std::chrono;


using VB  = vector<bool>;
using VVB = vector<VB>;
using VS  = vector<string>;
using VVS = vector<VS>;
using VII = vector<pair<int,int>>;
using VVI = vector<vector<int>>;


typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *l;
    TreeNode *r;
    TreeNode(int x) : val(x), left(NULL), right(NULL), l(left), r(right) {}
} TreeNode;

typedef struct Point{
  int x, y;
} Point;



#endif /* PNSEI_HPP_ */
