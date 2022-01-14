#include <bits/stdc++.h>
using namespace std;


const int n = 12;
bool visited[n + 1];
int dist[n + 1];
// each pair: <head, edge_weight>
vector<pair<int, int> > adj[n + 1] = {
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
// each pair: <dist[node], node>
// Alternatively, the default priority queue can be used (with less instead of
// greater), but the pair pushed upon relaxation should contain -dist[node].
priority_queue<pair<int, int>,
               vector<pair<int, int> >,
               greater<pair<int, int> > > pq;


// O((m + n)logn), n: number of nodes, m: number of edges
void dijkstra(int s)
{
  memset(dist, 0x3f, sizeof(dist));
  dist[s] = 0;
  memset(visited, false, sizeof(visited));
  pq.push(make_pair(0, s));

  while (!pq.empty()) {
    int u = pq.top().second; pq.pop();
    if (visited[u]) continue;
    visited[u] = true;
    for (auto ne : adj[u]) {
      int v = ne.first, w = ne.second;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
}


int main()
{
  int source = 1;
  dijkstra(1);

  for (int i = 1; i <=n; ++i) {
    cout << source << " -> " << i << " : " << dist[i] << '\n';
  }
}