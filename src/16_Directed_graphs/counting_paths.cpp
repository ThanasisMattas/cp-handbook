/**
 * Two solutions, both O(E + V)
 *  1. recursion + dp
 *     needs reverse_adj, but very simple implementation
 *  2. topological sort + O(V + E) loop
 *     if the graph is large, stack overflow of deep recursion can be avoided
 *     with the iterative dfs implementation
 */

#include <bits/stdc++.h>
using namespace std;


const int n = 6;
vector<int> adj[n + 1] = {
  {},
  {2, 4},  // 1
  {3},     // 2
  {6},     // 3
  {5},     // 4
  {2, 3},  // 5
  {}       // 6
};
// reverse adjacency list (each vector holds the nodes that have an edge
// towards the index-node)
vector<int> reverse_adj[n + 1];

// number of paths from 1 to any node
int paths[n + 1] = {0};


void populate_reverse_adj()
{
  for (int u = 1; u <=n; ++u) {
    for (int v : adj[u]) {
      reverse_adj[v].push_back(u);
    }
  }
}


void solve_dp_rec(int v)
{
  for (int u : reverse_adj[v]) {
    if (paths[u] == 0) solve_dp_rec(u);
    paths[v] += paths[u];
  }
}


// O(V+E)
void solve_dp()
{
  populate_reverse_adj();
  for (int x = 1; x <=n; ++x) {
    memset(paths, 0x00, sizeof(paths));
    paths[1] = 1;
    solve_dp_rec(x);
    cout << "1->" << x << " paths: " << paths[x] << '\n';
  }
}


vector<int> top_sort;
int state[n + 1] = {0};


// returns true if a cycle is detected
bool dfs_top_sort(int u, int u_prev=-1)
{
  if (state[u] == 2) return false;
  if (state[u] == 1) return true;

  state[u] = 1;
  for (auto u_next : adj[u])
    if (u_prev != u_next)
      if (dfs_top_sort(u_next, u))
        return true;

  state[u] = 2;
  top_sort.push_back(u);
  return false;
}


void populate_top_sort()
{
  for (int u = 1; u <= n; ++u) {
    if (dfs_top_sort(u)) {
      cout << "Cycle detected\n";
      break;
    }
  }
}


// O(V+E)
void solve_top_sort()
{
  populate_top_sort();
  paths[1] = 1;

  for (auto it = top_sort.rbegin(); it != top_sort.rend(); ++it) {
    int u = *it;
    for (auto v : adj[u]) {
      paths[v] += paths[u];
    }
  }

  for (int u = 1; u <= n; ++u)
    cout << "1->" << u << " paths: " << paths[u] << '\n';
}


int main()
{
  cout << "top sort:"
       << '\n';
  solve_top_sort();
  cout << '\n'
       << "dp:"
       << '\n';
  solve_dp();
}