#include <bits/stdc++.h>
using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
  return out;
}


const int n = 8;
vector<int> v{5, 8, 6, 3, 1, 7, 2, 6};
vector<int> tree(2 * n);


// amortized O(n)
void populate_tree()
{
  copy(v.begin(), v.end(), tree.begin() + n);

  for (int i = 1; i <= (int)log2(n); ++i) {
    for(int j = (n >> i); j < (n >> (i - 1)); ++j) {
      tree[j] = min(tree[2 * j], tree[2 * j + 1]);
    }
  }
}


// O(log(n))
int minimum(int a, int b)
{
  a += n;
  b += n;
  int s = INT_MAX;
  while (a <= b) {
    if (a % 2 == 1) s = min(s, tree[a++]);
    if (b % 2 == 0) s = min(s, tree[b--]);
    a /= 2;
    b /= 2;
  }
  return s;
}


// O(log(n))
void update(int k, int val)
{
  // v[k] = val;
  k += n;
  tree[k] = val;
  for (k /= 2; k >= 1; k /= 2)
    tree[k] = min(tree[2 * k], tree[2 * k + 1]);
}


// O(log(n))
int argmin()
{
  int levels = (int)log2(n);
  int k = 1;
  while (levels--)
    k = (tree[2 * k] < tree[2 * k + 1]) ? 2 * k : 2 * k + 1;
  return k - n;
}


// O(n + qlog(n))
void solve()
{
  populate_tree();
  cout << v << '\n';
  cout << tree << '\n';

  cout << "argmin: " << argmin() << '\n';

  int q;
  cout << "Number of queries: ";
  cin >> q;

  int type;
  int a, b;
  cout << "For sum queries enter: 1 a b.\n"
       << "For update queries enter: 2 idx val\n";

  while (q--) {
    cout << "Query: ";
    cin >> type >> a >> b;

    if (type == 1) cout << minimum(a, b) << '\n';
    else update(a, b);
  }
}


int main() {solve();}
