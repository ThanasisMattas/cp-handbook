#include<bits/stdc++.h>
using namespace std;


vector<int> v{-1, 2, 4, -3, 5, 2, -5, 2};


// O(n)
void solve()
{
  int sum = 0;
  int best = -1e9;
  for (auto i : v) {
    sum = max(sum + i, i);
    best = max(best, sum);
  }
  cout << best << '\n';
}
