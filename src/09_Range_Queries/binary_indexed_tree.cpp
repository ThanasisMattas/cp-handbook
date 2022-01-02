#include <bits/stdc++.h>
using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
  return out;
}


const int n = 8;
vector<int> v{0, 1, 3, 4, 8, 6, 1, 4, 2};
vector<int> tree(n + 1);


// O(n)
void populate_tree()
{
  vector<int> cumsum(n + 1);
  partial_sum(v.begin(), v.end(), cumsum.begin());

  for (int k = 1; k <= n; ++k) {
    int max_power = k & -k;
    tree[k] = cumsum[k] - cumsum[k - max_power];
  }
}


// O(log(n))
int sum(int k)
{
  int s = 0;
  while (k >= 1) {
    s += tree[k];
    k -= k & -k;
  }
  return s;
}


// O(log(n))
void update(int k, int new_val)
{
  // v[k] = new_val;
  int diff = new_val - v[k];
  while (k <= n) {
    tree[k] += diff;
    k += k & -k;
  }
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

    if (type == 1) cout << sum(b) - sum(a - 1) << '\n';
    else update(a, b);
  }
}


int main() {solve();}
