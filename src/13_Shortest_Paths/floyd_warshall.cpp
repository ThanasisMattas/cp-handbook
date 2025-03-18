#include <bits/stdc++.h>
using namespace std;


const int n = 12;
const int f = INT_MAX / 2;
int dist[n + 1][n + 1];
int adj[n + 1][n + 1] = {
  {f, f, f, f, f, f, f, f, f, f, f, f, f},
  {f, 0, 5, f, f, f, 1, f, f, 15, f, f, f},   //  1
  {f, 1, 0, -2, f, 3, f, f, f, f, f, f, f},   //  2
  {f, f, 3, 0, 1, f, 4, f, f, f, f, f, f},    //  3
  {f, f, f, 2, 0, 3, 1, f, f, f, f, f, f},    //  4
  {f, f, 3, f, 8, 0, f, f, f, f, f, f, f},    //  5
  {f, 1, f, f, -1, f, 0, 8, f, f, 12, f, f},  //  6
  {f, f, f, f, f, f, 5, 0, 12, f, f, f, 3},   //  7
  {f, f, f, f, f, f, f, 9, 0, 7, f, 5, -2},   //  8
  {f, f, f, 8, f, f, -1, f, f, 0, f, 4, f},   //  9
  {f, -1, f, 6, f, f, f, f, f, 2, 0, f, f},   // 10
  {f, f, f, f, f, f, f, 14, f, 12, f, 0, f},  // 11
  {f, f, 15, f, f, 1, 1, 2, f, -3, f, f, 0}   // 12
};


// O(n^3)
void floyd_warshall()
{
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
}


void print_dist()
{
  cout << setw(4) << ' ';
  for (int i = 1; i <= n; ++i) {
    cout << setw(4) << i;
  }
  cout << '\n';
  cout << "    " << setw(4 * n) << setfill('-') << "";
  cout << setfill(' ') << '\n';

  for (int i = 1; i <= n; ++i) {
    cout << setw(2) << i << " |";
    for (int j = 1; j <= n; ++j) {
      if (dist[i][j] == f) cout << setw(4) << "inf";
      else cout << setw(4) << dist[i][j];
    }
    cout << '\n';
  }
}


/* Example of populating adj and dist with input as edge-list
 * void solve()
 * {
 *   int n, m;
 *   int a, b, w;
 *   cin >> n >> m;
 *
 *   int adj[n + 1][n + 1];
 *   int dist[n + 1][n + 1];
 *   memset(adj, 0x3f, sizeof(adj));
 *   memset(dist, 0x3f, sizeof(dist));
 *   for (int i = 1; i <= n; ++i) adj[i][i] = dist[i][i] = 0;
 *
 *   while (m--) {
 *     cin >> a >> b >> w;
 *     adj[a][b] = dist[a][b] = w;
 *     // for undirected, also:
 *     // adj[b][a] = dist[b][a] = w;
 *   }
 *
 *   floyd_warshall();
 * }
 */

int main()
{
  // init dist with direct edges
  memcpy(dist, adj, sizeof(adj));
  floyd_warshall();
  print_dist();
}
