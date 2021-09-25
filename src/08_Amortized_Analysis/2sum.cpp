#include <bits/stdc++.h>
using namespace std;


int arr[] = {9, 4, 6, 1, 9, 5, 10, 7};
const int x = 12;

void solve()
{
  int n = sizeof(arr) / sizeof(arr[0]);
  sort(arr, arr + n);
  int* l = arr;
  int* r = arr + n - 1;
  int sum = 0;

  // cout << "l r sum\n"
  //      << distance(arr, l) << ' ' << distance(arr, r) << ' ' << *l + *r << '\n';
  while (distance(l, r) > 0) {
    if (sum == x) {
      cout << *l << ' ' << *r << '\n';
      return;
    }
    else if (sum < x) l += 1;
    else r -= 1;
    sum = *l + *r;
    // cout << distance(arr, l) << ' ' << distance(arr, r) << ' ' << sum << '\n';
  }
  cout << "IMPOSSIBLE\n";
}


int main()
{
  solve();
}