#include <bits/stdc++.h>
using namespace std;


const int n = 100, s = 1;
bool visited[n + 1];
int dist[n + 1];
vector<pair<int, int> > adj[n + 1];  // head, edge_weight
priority_queue<pair<int, int>,       // path_to_node_weight, node
               vector<pair<int, int> >,
               greater<pair<int, int> > > pq;


void dijkstra()
{
  memset(dist, 0x3f, sizeof(dist));
  dist[s] = 0;
  memset(visited, false, sizeof(visited));
  visited[s] = true;
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


vector<int> adj_list[n + 1];

void dfs_graph(int u)
{
  if (visited[u]) return;
  visited[u] = true;
  for (auto v : adj_list[u]) dfs_graph(v);
}

void dfs_tree(int u, int u_prev)
{
  for (auto u_next : adj_list[u]) {
    if (u_next == u_prev) continue;
    dfs_tree(u_next, u);
  }
}


bool disc[n + 1];
queue<int> q;

void bfs(int s)
{
  memset(dist, 0x3f, sizeof(dist));
  dist[s] = 0;
  memset(disc, false, sizeof(disc));
  disc[s] = true;
  q.push(s);

  while(!q.empty()) {
    int u = q.front(); q.pop();
    for (auto v : adj_list[u]) {
      if (disc[v]) continue;
      disc[v] = true;
      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }
}


stack<int> st;

void dfs(int s)
{
  memset(dist, 0x3f, sizeof(dist));
  dist[s] = 0;
  memset(disc, false, sizeof(disc));
  disc[s] = true;
  st.push(s);

  while(!st.empty()) {
    int u = st.top(); q.pop();
    for (auto v : adj_list[u]) {
      if (disc[v]) continue;
      disc[v] = true;
      dist[v] = dist[u] + 1;
      st.push(v);
    }
  }
}
