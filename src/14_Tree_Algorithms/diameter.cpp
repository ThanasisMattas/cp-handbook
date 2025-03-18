#include <bits/stdc++.h>
using namespace std;


//              1
//        2           3
//    4       5   6       7
// 8     9                   12
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
// len to the farthest leaf
int to_leaf[n + 1] = {0};
// max len of the paths with the i node as the highest point
int max_len[n + 1] = {0};


// O(n)
// Calculates the longest path, whose highest point is u. In the book it is
// refered as dp; however both methods here use DP, DFS and recursion.
void solve_highest_point(int u, int u_prev=0)
{
  // In order to be a leaf, the single neighbor has to be u_prev.
  if ((adj[u].size() == 1) && (adj[u][0] == u_prev)) {
    to_leaf[u_prev] = max(to_leaf[u_prev], 1);
    return;
  }

  int first_max = 0;
  int second_max = 0;

  for (auto u_next : adj[u]) {
    if (u_next == u_prev) continue;
    solve_highest_point(u_next, u);

    if (to_leaf[u_next] > first_max) {
      second_max = first_max;
      first_max = to_leaf[u_next];
    } else if (to_leaf[u_next] > second_max) {
      second_max = to_leaf[u_next];
    }

    to_leaf[u] = first_max + 1;
    // If the tree was rooted to a node with a single child, we cannot add 2,
    // since there are not 2 separate branches. In that case, we either add 1
    // instead of 2 or max_len is the same as to_leaf.
    max_len[u] = first_max + second_max + 1 + (bool)u_prev;
  }
}


// the farthest leaf
int leaf[n + 1];


// O(n)
void dfs(int u, int u_prev=0)
{
  // In order to be a leaf, the single neighbor has to be u_prev.
  if ((adj[u].size() == 1) && (adj[u][0] == u_prev)) {
    if (to_leaf[u_prev] == 0) {
      to_leaf[u_prev] = 1;
      leaf[u_prev] = u;
    }
  } else {
    for (auto u_next : adj[u]) {
      if (u_next == u_prev) continue;
      dfs(u_next, u);
      if (to_leaf[u_next] + 1 > to_leaf[u]) {
        to_leaf[u] = to_leaf[u_next] + 1;
        leaf[u] = leaf[u_next];
      }
    }
  }
}


// O(n)
// Calculates the longest path, by finding the farthest leaf from a random
// node and then the farthest leaf of that leaf. In the book it is refered as
// DFS; however, both methods here use DP, DFS and recursion.
int solve_farthest_leaf_to_farthest_leaf()
{
  // Step 1: Go to the farthest leaf, starting from a random node.
  int s = 4;
  dfs(s);
  int farthest_leaf = leaf[s];

  // Step 2: Go to the farthest leaf, starthing from that leaf.
  memset(to_leaf, 0, sizeof(to_leaf));
  memset(leaf, 0, sizeof(leaf));
  dfs(farthest_leaf);
  return to_leaf[farthest_leaf];
}


int main()
{
  solve_highest_point(12);
  int diameter1 = *max_element(max_len, max_len + n + 1);
  memset(to_leaf, 0, sizeof(to_leaf));
  int diameter2 = solve_farthest_leaf_to_farthest_leaf();
  cout << "diameter: " << diameter1 << '\n';
  assert(diameter1 == diameter2);
}
