#include <bits/stdc++.h>

using namespace std;


vector<int> v{1, 3, 2, 5, 1, 1, 2, 3};
const int x = 8;


void solve()
{
  size_t l = 0, r = 0;
  size_t sum = v[0];

  while ((r - l >= 0) && (r < v.size())) {
    if (sum == x) {
      copy(v.begin() + l, v.begin() + r + 1, ostream_iterator<int>(cout, " "));
      cout << '\n';
      return;
    } else if ((sum < x) && (sum + v[r + 1] <= x)) {
      ++r;
      sum += v[r];
    } else {
      sum -= v[l];
      ++l;
    }
  }
  cout << "IMPOSSIBLE\n";
}


int main()
{
  solve();
}
