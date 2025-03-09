#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include "../compete.hpp"
using namespace std;


vector<int> v{-5, -3, -1, 2, 2, 4, 5};
int x = 4;


// O(log(n))
void binary_search_1()
{
  int a = 0;
  int b = v.size() - 1;
  while (a <= b) {
    int k = (a + b) / 2;
    if (v[k] == x) {
      cout << k << '\n';
      break;
    }
    if (v[k] > x) b = k - 1;
    else a = k + 1;
  }
}


// O(log(n))
void binary_search_2()
{
  int n = v.size();
  int k = 0;
  for (int b = n / 2; b >= 1; b /= 2) {
    while ((k + b < n) && (v[k + b] <= x)) {
      k += b;
      if (v[k] == x) {
        cout << k << '\n';
        break;
      }
    }
  }
}


int main()
{
  cout << v << '\n';
  cout << x << " at ";
  binary_search_2();
}