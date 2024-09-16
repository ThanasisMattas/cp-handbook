#include <bits/stdc++.h>
using namespace std;


const int m = 8;
vector<tuple<int, int, int> > edge_list = {
  make_tuple(1, 2, 3),
  make_tuple(1, 5, 5),
  make_tuple(2, 5, 6),
  make_tuple(2, 3, 5),
  make_tuple(5, 6, 2),
  make_tuple(3, 6, 3),
  make_tuple(3, 4, 9),
  make_tuple(6, 4, 7)
};

const int n = 12;
const int source = 1;
bool visited[n + 1];
int dist[n + 1];
int last[n + 1];
vector<pair<int, int> > mst;
// each pair: <head, edge_weight>
vector<pair<int, int> > adj[n + 1] = {
  {},
  {{2, 3}, {5, 5}},          //  1
  {{1, 3}, {3, 5}, {5, 6}},  //  2
  {{2, 5}, {4, 9}, {6, 3}},  //  3
  {{3, 9}, {6, 7}},          //  4
  {{1, 5}, {2, 6}, {6, 2}},  //  5
  {{3, 3}, {4, 7}, {5, 2}}   //  6
};
// Using greater as predicate, we get a min priority queue. Alternatively, the
// default max priority queue can be used (with less instead of greater), but
// the pair pushed upon relaxation should contain -dist[node], for the smaller
// distance to get higher priority.
// each pair: <dist[node], node>
priority_queue<pair<int, int>,
               vector<pair<int, int> >,
               greater<pair<int, int> > > pq;


// O((m + n)logn), n: number of nodes, m: number of edges
void prim(int s)
{
  memset(dist, 0x3f, sizeof(dist));
  dist[s] = 0;
  last[s] = -1;
  memset(visited, false, sizeof(visited));
  pq.push(make_pair(0, s));

  while (!pq.empty()) {
    int u = pq.top().second; pq.pop();
    if (visited[u]) continue;
    visited[u] = true;
    if (u != s) mst.push_back(make_pair(u, last[u]));
    for (auto& [v, w] : adj[u]) {
      if (dist[v] > w) {
        dist[v] = w;
        last[v] = u;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
}


int main()
{
  prim(source);
  for (auto& [a, b] : mst) cout << a << " - " << b << '\n';
}
