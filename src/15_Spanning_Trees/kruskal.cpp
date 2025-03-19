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


// apparently link is reserved
int arc[m];
int set_size[m];


// O(logn)
int representative(int x)
{
  while (x != arc[x]) x = arc[x];
  return x;
}


// O(logn)
bool same(int a, int b) {return representative(a) == representative(b);}


// O(logn)
// Makes sure that the length of each chain is O(logn), by connecting the
// smaller set to the larger set.
void unite(int a, int b)
{
  a = representative(a);
  b = representative(b);
  if (set_size[a] < set_size[b]) swap(a, b);
  set_size[a] += set_size[b];
  arc[b] = a;
}


struct shorter_edge
{
  bool operator()(tuple<int, int, int> e1, tuple<int, int, int> e2)
  {
    return get<2>(e1) < get<2>(e2);
  }
};


// O(mlog(n)) if edge_list is sorted else O(mlog(m))
void kruskal()
{
  sort(edge_list.begin(), edge_list.end(), shorter_edge());  // O(mlog(m))
  iota(arc, arc + m, 0);
  fill(set_size, set_size + m, 1);
  int cost = 0;

  cout << "MST:\n";
  for (auto&& [a, b, w] : edge_list) {  // O(mlog(n))
    if (!same(a, b)) {
      cost += w;
      unite(a, b);
      // this is an MST edge
      cout << a << " - " << b << '\n';
    }
  }
  cout << "total cost: " << cost << '\n';
}


int main() {
  kruskal();
}
