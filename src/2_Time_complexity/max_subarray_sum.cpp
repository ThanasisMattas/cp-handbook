#include<bits/stdc++.h>

using namespace std;


vector<int> v{-1, 2, 4, -3, 5, 2, -5, 2};


// O(n)
int main()
{
  int sum = 0, best = 0;
  for (const int& i : v) {
    sum = max(sum + i, i);
    best = max(best, sum);
  }

  cout << best << '\n';
}
