#include <bits/stdc++.h>
using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
  return out;
}


const int n = 8;
vector<int> v{1, 3, 4, 8, 6, 1, 4, 2};
vector<int> tree(n + 1);


// O(n)
void populate_tree()
{
  vector<int> cumsum(n + 1);
  // cumulative sum begins at index 1
  partial_sum(v.begin(), v.end(), cumsum.begin() + 1);

  for (int k = 1; k <= n; ++k) {
    tree[k] = cumsum[k] - cumsum[k - (k & -k)];
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
  // offset with -1, to meet the zero indexed vector
  // v[k - 1] = new_val;  // however, there is no need to update v
  int diff = new_val - v[k - 1];
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
  // NOTE: query indexes are 1-based
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
