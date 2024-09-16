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


int link[m];
int set_size[m];


// representative
// O(logn)
int repr(int x)
{
  while (x != link[x]) x = link[x];
  return x;
}


// O(logn)
bool same(int a, int b) {return repr(a) == repr(b);}


// O(logn)
// Makes sure that the length of each chain is O(logn), by connecting the
// smaller set to the larger set.
void unite(int a, int b)
{
  a = repr(a);
  b = repr(b);
  if (set_size[a] < set_size[b]) swap(a, b);
  set_size[a] += set_size[b];
  link[b] = a;
}


struct shorter_edge
{
  bool operator()(tuple<int, int, int> e1, tuple<int, int, int> e2)
  {
    return get<2>(e1) < get<2>(e2);
  }
};


// O(mlog(m))
void kruskal()
{
  sort(edge_list.begin(), edge_list.end(), shorter_edge());
  iota(link, link + m, 0);
  fill(set_size, set_size + m, 1);

  for (auto&& [a, b, w] : edge_list) {
    if (!same(a, b)) {
      unite(a, b);
      // this is an MST edge
      cout << a << " - " << b << '\n';
    }
  }
}


int main() {kruskal();}
