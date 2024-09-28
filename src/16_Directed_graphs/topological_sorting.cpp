#include <bits/stdc++.h>
using namespace std;


const int n = 6;
vector<int> adj[n + 1] = {
  {},
  {2},     // 1
  {3},     // 2
  {6},     // 3
  {1, 5},  // 4
  {2, 3},  // 5
  {}       // 6
};
int state[n + 1] = {0};
vector<int> top_sort;
bool cycle = false;


void dfs(int u, int u_prev)
{
  if (!cycle) {
    // There is no way to get to a node with status 2. If there was, it would
    // mean that its ansestors are still being processed, therefore it would
    // still be in status 1.
    if (state[u] == 1) cycle = true;
    else if (state[u] == 0) {
      state[u] = 1;
      for (auto u_next : adj[u]) {
        if (u_next != u_prev) dfs(u_next, u);
      }
      state[u] = 2;
      top_sort.push_back(u);
    }
  }
}


// O(V+E)
void solve()
{
  for (int u = 1; u <= n; ++u) {
    // A new DFS runs for each node in state 0, in case the previous searches
    // did not reach it (multiple connected components).
    if (state[u] == 0) dfs(u, 0);
    else if (state[u] == 1) {
      cycle = true;
      break;
    }
  }

  if (cycle) {
      cout << "Cycle detected\n";
  } else {
    copy(top_sort.rbegin(), top_sort.rend(), ostream_iterator<int>(cout, " "));
    cout << '\n';
  }
}


int main()
{
  solve();
  // clean-up and introduce a cycle (reverse edge (5, 3))
  adj[3] = vector<int>{5, 6};
  adj[5] = vector<int>{2};
  cycle = false;
  top_sort.clear();
  memset(state, 0, sizeof(state));
  solve();
}
