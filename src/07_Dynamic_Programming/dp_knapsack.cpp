#pragma GCC optimize ("03")
#include <bits/stdc++.h>
#include "../compete.hpp"
using namespace std;


int w[] = {1, 3, 3, 5};
const int n = 4;
const int max_w = 12;


// O(nx) time, n: number of values, x: sum
// O(nx) space
void solve_1()
{
  Timer t(__func__);

  bool poss[max_w + 1][n + 1];
  memset(poss, false, sizeof(poss));
  poss[0][0] = true;

  for (int k = 1; k <= n; ++k) {
    for (int x = 0; x <= max_w; ++x) {
      // w index must be offset by -1, because the 0th index of poss corre-
      // sponds to no weights. Namely, the 1st index of poss corresponds to
      // the 0th weight at w.
      if (x - w[k - 1] >= 0)
        poss[x][k] |= poss[x - w[k - 1]][k - 1];
      poss[x][k] |= poss[x][k - 1];
    }
  }

  // Optional printing block:
  cout << "  | ";
  for (int x = 0; x <= max_w; ++x) {
    cout << right << setw(2) << x << ' ';
  }
  cout << '\n';
  cout << "0 | ";
  for (int x = 0; x <= max_w; ++x) {
    cout << right << setw(2) << (poss[x][0] ? "X": " ") << ' ';
  }
  cout << '\n';

  for (int k = 1; k <= n; ++k) {
    cout << w[k - 1] << " | ";
    for (int x = 0; x <= max_w; ++x) {
      cout << right << setw(2) << (poss[x][k] ? "X": " ") << ' ';
    }
    cout << '\n';
  }
}


// O(nx) time, n: number of values, x: sum
// O(x)  space
void solve_2()
{
  Timer t(__func__);

  bool poss[max_w + 1];
  memset(poss, false, sizeof(poss));
  poss[0] = true;

  for (int k = 0; k < n; ++k)
    for (int x = max_w; x >= 0; --x)
      if (poss[x])
        poss[x + w[k]] = true;

  // Optional printing block:
  cout << "  | ";
  for (int x = 0; x <= max_w; ++x) {
    cout << right << setw(2) << x << ' ';
  }
  cout << '\n';

  cout << "  | ";
  for (int x = 0; x <= max_w; ++x) {
    cout << right << setw(2) << (poss[x] ? "X": " ") << ' ';
  }
  cout << '\n';
}


int main()
{
  solve_1();
  cout << '\n';
  solve_2();
}