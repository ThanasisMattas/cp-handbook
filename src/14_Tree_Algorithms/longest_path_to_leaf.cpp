#include <bits/stdc++.h>
using namespace std;


//              1
//        2           3
//    4       5   6       7
// 8     9            12
//     10 11
const int n = 12;
vector<int> adj[n + 1] = {
  {},
  {2, 3},       //  1
  {1, 4, 5},    //  2
  {1, 6, 7},    //  3
  {2, 8, 9},    //  4
  {2},          //  5
  {3},          //  6
  {3, 12},      //  7
  {4},          //  8
  {4, 10, 11},  //  9
  {9},          // 10
  {9},          // 11
  {7}           // 12
};
int len[n + 1] = {0};


// O(n)
void dfs(int u, int u_prev)
{
  // In order to be a leaf, the single neighbor has to be u_prev.
  if ((adj[u].size() == 1) && (adj[u][0] == u_prev)) {
    len[u_prev] = max(len[u_prev], 1);
  } else {
    for (auto u_next : adj[u]) {
      if (u_next == u_prev) continue;
      dfs(u_next, u);
      len[u] = max(len[u], len[u_next] + 1);
    }
  }
}


int main()
{
  int node = 1;
  dfs(node, 0);
  cout << node << " : " << len[node] << '\n';
}

