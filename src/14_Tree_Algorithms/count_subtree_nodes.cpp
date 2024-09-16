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
int counter[n + 1];


void dfs(int u, int u_prev)
{
  counter[u] = 1;
  for (auto u_next : adj[u]) {
    if (u_next == u_prev) continue;
    dfs(u_next, u);
    counter[u] += counter[u_next];
  }
}


int main()
{
  dfs(1, 0);

  for (int i = 1; i <= n; ++i)
    cout << setw(2) << i << " : " << counter[i] << '\n';
}

