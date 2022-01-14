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
  // discovered
  bool disc[adj.size()];
  int dist[adj.size()];
  memset(disc, false, sizeof(disc));
  memset(dist, 0x3f, sizeof(dist));
  disc[s] = true;
  dist[s] = 0;
  vector<int> seq;
  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int u = q.front(); q.pop();
    seq.push_back(u);
    for (auto v : adj[u]) {
      if (!disc[v]) {
        disc[v] = true;
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return seq;
}


vector<int> dfs(const vector<unordered_set<int> >& adj, int s)
{
  bool disc[adj.size()];
  memset(disc, false, sizeof(disc));
  disc[s] = true;
  stack<int> st;
  st.push(s);
  vector<int> seq;

  while (!st.empty()) {
    int u = st.top(); st.pop();
    seq.push_back(u);
    for (auto v : adj[u]) {
      if (!disc[v]) {
        disc[v] = true;
        st.push(v);
      }
    }
  }
  return seq;
}


const int n = 100;
vector<int> adj_list[n + 1];
bool disc[n + 1];


void dfs_rec_graph(int u)
{
  // process u
  for (auto v : adj_list[u]) {
    if (disc[v]) continue;
    disc[v] = true;
    dfs_rec_graph(v);
  }
}


// No need for discovered flags. Just do not go back to the parent node.
void dfs_rec_tree(int u, int u_prev)
{
  // process u
  for (auto u_next : adj_list[u]) {
    if (u_next == u_prev) continue;
    dfs_rec_tree(u_next, u);
  }
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
