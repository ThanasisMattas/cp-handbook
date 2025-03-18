#include <bits/stdc++.h>
using namespace std;


//        1
//    2   3   4
//   5 6
const int n = 6;
vector<int> adj[n + 1] = {
  {},
  {2, 3, 4},  //  1
  {1, 5, 6},  //  2
  {1},        //  3
  {1},        //  4
  {2},        //  5
  {2}         //  6
};
int len_1[n + 1] = {0};
int len_2[n + 1] = {0};
int max_len_through_this_child[n + 1];


// O(n)
// Finds the lengths of the 2 longest paths, that go though the children of
// each node.
void part_1(int u, int u_prev)
{
  // Base case: u is a leaf
  if ((adj[u].size() == 1) && (adj[u][0] == u_prev)) {
    if (len_1[u_prev] == 0) {
      len_1[u_prev] = 1;
    } else {
      len_2[u_prev] = 1;
    }
  } else {
    for (auto u_next : adj[u]) {
      if (u_next == u_prev) continue;
      part_1(u_next, u);
      if (len_1[u] < len_1[u_next] + 1) {
        len_2[u] = len_1[u];
        len_1[u] = len_1[u_next] + 1;
        max_len_through_this_child[u] = u_next;
      } else if (len_2[u] < len_1[u_next] + 1) {
        len_2[u] = len_1[u_next] + 1;
      }
    }
  }
}


// O(n)
// Finds the lengths of the 2 longest paths, that go through the children or
// the parent of each node.
void part_2(int u, int u_prev)
{
  if (max_len_through_this_child[u_prev] == u) {
    // max_len of u_prev goes through u
    if (len_2[u_prev] + 1 > len_1[u]) {
      len_2[u] = len_1[u];
      len_1[u] = len_2[u_prev] + 1;
      max_len_through_this_child[u] = u_prev;
    }
  } else {
    if (len_1[u_prev] + 1 > len_1[u]) {
      len_2[u] = len_1[u];
      len_1[u] = len_1[u_prev] + 1;
      max_len_through_this_child[u] = u_prev;
    }
  }

  for (auto u_next : adj[u]) {
    if (u_next != u_prev)
      part_2(u_next, u);
  }
}


int main()
{
  part_1(1, 0);
  part_2(1, 0);

  for (int u = 1; u <= n; ++u) cout << u << ": " << len_1[u] << '\n';
}