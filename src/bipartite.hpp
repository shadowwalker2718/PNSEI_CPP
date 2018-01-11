#include "pnsei.hpp"

namespace ns_bipartite {

// Ref:　https://www.geeksforgeeks.org/bipartite-graph/

// For strongly connected graph
bool isbipartite_imp(const VVB& G, set<int>& white, set<int>& black,
    int src = 0) {
  if (G.empty() || G[0].empty())
    throw invalid_argument("");
  assert(G.size() == G[0].size());
  int V = G.size();
  if (V == white.size() + black.size())
    return true;
  queue<int> q;
  q.push(src);
  white.insert(src);
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    const set<int>& dead = white.count(t) ? white : black;
    set<int>& live = white.count(t) ? black : white;
    for (int i = 0; i < V; ++i) {
      if (G[t][i]) {
        if (white.count(i) == 0 && black.count(i) == 0)
          q.push(i), live.insert(i);
        else if (dead.count(i))
          return false;
      }
    }
  }
#if __DEBUG__
  cout << "white:" << endl;
  copy(white.begin(), white.end(), ostream_iterator<int>(cout));
  cout << endl;
  cout << "black:" << endl;
  copy(black.begin(), black.end(), ostream_iterator<int>(cout));
  cout << endl;
#endif
  return true;
}

bool isbipartite(const VVB& G) {
  set<int> white, black;
  for (int i = 0; i < G.size(); ++i)
    if (!white.count(i) && !black.count(i) && !isbipartite_imp(G, white, black))
      return false;
  return true;
}

// BFS for Adjacency Matrix
void bfs(const VVB& G, int source) { // T: O(V^2)
  if (G.empty() || G[0].empty())
    return;
  assert(G.size() == G[0].size());
  set<int> visited;
  int V = G.size();
  queue<int> q;
  q.push(source);
  visited.insert(source);
  while (!q.empty()) {
    int t = q.front();
    q.pop();
#if __DEBUG__
    cout << t << "\n";
#endif
    for (int i = 0; i < V; ++i) { // loop through its neighbors
      if (G[t][i] && visited.count(i) == 0) {
        q.push(i), visited.insert(i);
      }
    }
  }
}

bool test() {
  VVB G = { { 0, 1, 0, 1 }, { 1, 0, 1, 0 }, { 0, 1, 0, 1 }, { 1, 0, 1, 0 } };
  bfs(G, 0);
  return isbipartite(G);
}

}
