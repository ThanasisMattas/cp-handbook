#include <bits/stdc++.h>
using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
  return out;
}


const int n = 8;
vector<int> v{5, 8, 6, 3, 2, 7, 2, 6};
vector<int> tree(2 * n);


// amortized O(n)
void populate_tree()
{
  copy(v.begin(), v.end(), tree.begin() + n);

  for (int i = 1; i <= (int)log2(n); ++i) {
    for(int j = (n >> i); j < (n >> (i - 1)); ++j) {
      tree[j] = tree[2 * j] + tree[2 * j + 1];
    }
  }
}


// O(log(n))
int sum(int a, int b)
{
  a += n;
  b += n;
  int s = 0;
  while (a <= b) {
    if (a % 2 == 1) s += tree[a++];
    if (b % 2 == 0) s += tree[b--];
    a /= 2;
    b /= 2;
  }
  return s;
}


// O(log(n))
void update(int k, int val)
{
  // v[k] = val;
  int x = val - v[k];
  for (k += n; k >= 1; k /= 2) tree[k] += x;
}


// O(n + qlog(n))
void solve()
{
  populate_tree();
  cout << v << '\n';
  cout << tree << '\n';

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

    if (type == 1) cout << sum(a, b) << '\n';
    else update(a, b);
  }
}


int main() {solve();}
