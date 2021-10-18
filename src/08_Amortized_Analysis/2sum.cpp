#include <bits/stdc++.h>
using namespace std;


vector<int> v{9, 4, 6, 1, 9, 5, 10, 7};
const int x = 12;


void solve()
{
  sort(v.begin(), v.end());
  int i = 0;
  int j = v.size() - 1;
  int s = v[i] + v[j];

  while ((s != x) && (j - i > 1)) {
    if (s < x) ++i;
    else --j;
    s = v[i] + v[j];
  }

  if (s == x) cout << v[i] << ' ' << v[j] << '\n';
  else cout << "IMPOSSIBLE\n";
}



int main()
{
  solve();
}