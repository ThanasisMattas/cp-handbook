#include <bits/stdc++.h>
using namespace std;


const int n = 12;
const int source = 1;
int dist[n + 1];
// each pair: <head, edge_weight>
vector<pair<int, int> > adj_validate_with_dijkstra[n + 1] = {
  {},
  {{2, 5}, {6, 1}, {10, 15}},          //  1
  {{1, 1}, {3, 2}, {5, 12}},           //  2
  {{2, 6}, {4, 4}, {6, 11}},           //  3
  {{3, 2}, {5, 3}, {6, 1}},            //  4
  {{2, 3}, {4, 8}},                    //  5
  {{1, 1}, {4, 9}, {7, 8}, {10, 16}},  //  6
  {{6, 10}, {8, 12}, {12, 2}},         //  7
  {{7, 9}, {9, 7}, {12, 3}},           //  8
  {{10, 3}, {8, 1}, {11, 11}},         //  9
  {{1, 1}, {9, 2}},                    // 10
  {{9, 12}},                           // 11
  {{7, 1}, {8, 20}}                    // 12
};
vector<pair<int, int> > adj[n + 1] = {
  {},
  {{2, 5}, {6, 1}, {10, 15}},           //  1
  {{1, 1}, {3, -2}, {5, 3}},            //  2
  {{2, 3}, {4, 1}, {6, 4}},             //  3
  {{3, 2}, {5, 3}, {6, 1}},             //  4
  {{2, 3}, {4, 8}},                     //  5
  {{1, 1}, {4, -1}, {7, 8}, {10, 16}},  //  6
  {{6, 5}, {8, 12}, {12, 3}},           //  7
  {{7, 9}, {9, 7}, {12, -2}},           //  8
  {{10, 3}, {8, 1}, {11, 11}},          //  9
  {{1, -1}, {9, 2}},                    // 10
  {{9, 12}},                            // 11
  {{7, 1}, {8, 20}}                     // 12
};


// O(nm)
// This is the SPFA (Shortest Path Faster Algorithm) version, where the
// algorithm is not visiting all the edges at each epoch. Rather, it visits
// only those that their distance was relaxed from infinity, because a path
// to those nodes is not yet constructed, hence it cannot be extended.
bool bellman_ford(int s)
{
  memset(dist, 0x3f, sizeof(dist));
  dist[s] = 0;
  // If no more updates are happening, the process should terminate there.
  bool halt;
  int inf = dist[0];

  // each shortest path can contain at most n − 1 edges
  for (int epoch = 1; epoch < n; ++epoch) {
    halt = true;
    for (int u = 1; u <= n; ++u) {
      if (dist[u] != inf) {
        for (auto& [v, w] : adj[u]) {
          if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            halt = false;
          }
        }
      }
    }
    if (halt) break;
  }

  // Check for negative cycles.
  if (!halt) {
    for (int u = 1; u <= n; ++u) {
      for (auto& [v, w] : adj[u]) {
        if (dist[v] > dist[u] + w) return false;
      }
    }
  }
  return true;
}


void solve()
{
  if (bellman_ford(source)) {
    for (int u = 1; u <=n; ++u) {
      cout << source << " -> " << u << " : " << dist[u] << '\n';
    }
  } else {
    cout << "Negative cycle detected\n";
  }
}


int main()
{
  solve();
  // Introduce a negative cycle.
  adj[3][1] = make_pair(2, 1);
  cout << '\n';
  solve();
}
