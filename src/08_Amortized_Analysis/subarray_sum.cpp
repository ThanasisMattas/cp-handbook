#include <bits/stdc++.h>

using namespace std;


vector<int> v{1, 3, 2, 5, 1, 1, 2, 3};
const int n = 8;
const int x = 8;


// amortized O(n)
// If a value of the array is >= x, this alg gets stuck.
void solve()
{
  size_t l = 0, r = 0;
  size_t sum = v[0];

  while ((r >= l) && (r < n)) {
    if (sum == x) {
      copy(v.begin() + l, v.begin() + r + 1, ostream_iterator<int>(cout, " "));
      cout << '\n';
      return;
    }
    if ((sum < x) && (sum + v[r + 1] <= x)) {
      ++r;
      sum += v[r];
    } else {
      sum -= v[l];
      ++l;
    }
  }
  cout << "IMPOSSIBLE\n";
}


// amortized O(n)
void solve2()
{
  int l = 0;
  int r = 0;
  int s = v[0];
  while (r < n) {
    if (s == x) {
      copy(v.begin() + l, v.begin() + r + 1, ostream_iterator<int>(cout, " "));
      cout << '\n';
      return;
    }
    if (s < x) {
      if (r == n - 1) break;
      ++r;
      s += v[r];
    }
    else {
      s -= v[l];
      if (l == r) ++r;
      ++l;
    }
  }
  cout << "IMPOSSIBLE\n";
}


int main() {solve2();}
