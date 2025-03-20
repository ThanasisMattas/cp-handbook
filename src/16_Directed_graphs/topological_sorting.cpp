#include <bits/stdc++.h>
#include "../compete.hpp"
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
deque<int> top_sort;


// O(V+E)
// Returns True if a cycle is detected, False otherwise.
bool dfs(int u)
{
  if (state[u] == 1) return true;
  if (state[u] == 2) return false;
  state[u] = 1;
  for (auto v : adj[u])
    if (dfs(v)) return true;
  state[u] = 2;
  top_sort.push_front(u);
  return false;
}


// O(V+E)
void solve()
{
  for (int u = 1; u <= n; ++u) {
    if (dfs(u)) {
      cout << "Cycle detected\n";
      return;
    }
  }
  cout << top_sort << '\n';
  // copy(top_sort.rbegin(), top_sort.rend(), ostream_iterator<int>(cout, " "));
  // cout << '\n';
}


int main()
{
  solve();
  // clean-up and introduce a cycle (reverse edge (5, 3))
  adj[3] = vector<int>{5, 6};
  adj[5] = vector<int>{2};
  top_sort.clear();
  memset(state, 0, sizeof(state));
  solve();
}
