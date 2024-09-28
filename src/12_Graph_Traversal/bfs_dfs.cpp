#include <bits/stdc++.h>
using namespace std;


template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  out << '[';
  if (!v.empty()) {
    copy(v.begin(), v.end(), ostream_iterator<int>(out, ", "));
    out << "\b\b";
  }
  out << ']';
  return out;
}


vector<int> bfs(const vector<unordered_set<int> >& adj, int s)
{
  bool visited[adj.size()];
  int dist[adj.size()];
  memset(visited, false, sizeof(visited));
  memset(dist, 0x3f, sizeof(dist));
  visited[s] = true;
  dist[s] = 0;
  vector<int> seq;
  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int u = q.front(); q.pop();
    seq.push_back(u);
    for (auto v : adj[u]) {
      if (!visited[v]) {
        visited[v] = true;
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return seq;
}


vector<int> dfs(const vector<unordered_set<int> >& adj, int s)
{
  bool visited[adj.size()];
  memset(visited, false, sizeof(visited));
  visited[s] = true;
  stack<int> st;
  st.push(s);
  vector<int> seq;

  while (!st.empty()) {
    int u = st.top(); st.pop();
    seq.push_back(u);
    for (auto v : adj[u]) {
      if (!visited[v]) {
        visited[v] = true;
        st.push(v);
      }
    }
  }
  return seq;
}


const int n = 100;
vector<int> adj[n + 1];
bool visited[n + 1];


void dfs_rec_graph(int u)
{
  if (visited[u]) return;
  visited[u] = true;
  // process u
  for (auto v : adj[u]) {
    dfs_rec_graph(v);
  }
}


// No need for visitedovered flags. Just do not go back to the parent node.
void dfs_rec_tree(int u, int u_prev)
{
  // process u
  for (auto u_next : adj[u])
    if (u_next != u_prev)
      dfs_rec_tree(u_next, u);
}


int main()
{
  vector<unordered_set<int> > adj{
    unordered_set<int>{},
    unordered_set<int>{2, 6, 10},
    unordered_set<int>{1, 3, 5},
    unordered_set<int>{2, 4},
    unordered_set<int>{3, 5, 6},
    unordered_set<int>{2, 4},
    unordered_set<int>{1, 4, 7},
    unordered_set<int>{6, 8, 12},
    unordered_set<int>{7, 9, 12},
    unordered_set<int>{10, 8, 11},
    unordered_set<int>{1, 9},
    unordered_set<int>{9},
    unordered_set<int>{7, 8}
  };

  cout << bfs(adj, 1) << '\n';
  cout << dfs(adj, 1) << '\n';
}
