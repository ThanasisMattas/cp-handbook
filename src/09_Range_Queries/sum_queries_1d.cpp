#include <bits/stdc++.h>
using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) {
    copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
    out << '\b';
  }
  return out;
}


vector<int> v{1, 3, 4, 8, 6, 1, 4, 2};
int q;
int a, b;


void solve()
{
  // cumulative vector
  vector<int> cumsum(v.size());
  partial_sum(v.begin(), v.end(), cumsum.begin());

  cout << "Give number of queries: ";
  cin >> q;

  cout << v << '\n';

  while (q--) {
    cout << "Give subset limits: ";
    cin >> a >> b;
    cout << "Subset sum: " << cumsum[b] - cumsum[a] + v[a] << '\n';
  }
}


int main() {solve();}
