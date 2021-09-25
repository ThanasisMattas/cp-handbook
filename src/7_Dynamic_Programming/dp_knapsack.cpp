#include <bits/stdc++.h>

using namespace std;


int w[] = {0, 1, 3, 3, 5};


// O(nx) time, n: number of values, x: sum
// O(nx) space
void solve_1()
{
  int n = sizeof(w) / sizeof(w[0]);
  int max_w = accumulate(w, w + n, 0);
  // possible
  bool pos[max_w+1][n];
  memset(pos, false, sizeof(pos));
  pos[0][0] = true;

  for (int k = 1; k < n; ++k) {
    for (int x = 0; x <= max_w; ++x) {
      if (x - w[k] >= 0)
        pos[x][k] |= pos[x - w[k]][k - 1];
      pos[x][k] |= pos[x][k-1];
    }
  }

  cout << "  | ";
  for (int i = 0; i <= max_w; ++i) {
    cout << right << setw(2) << i << ' ';
  }
  cout << '\n';

  for (int j = 0; j < n; ++j) {
    cout << w[j] << " | ";
    for (int i = 0; i <= max_w; ++i) {
      cout << right << setw(2) << (pos[i][j] ? "X": " ") << ' ';
    }
    cout << '\n';
  }
}


// O(nx) time, n: number of values, x: sum
// O(x)  space
void solve_2()
{
  int n = sizeof(w) / sizeof(w[0]);
  int max_w = accumulate(w, w + n, 0);
  bool pos[max_w + 1];
  memset(pos, false, sizeof(pos));
  pos[0] = true;

  for (int k = 1; k < n; ++k)
    for (int x = max_w; x >= 0; --x)
      if (pos[x])
        pos[x + w[k]] = true;

  cout << "  | ";
  for (int i = 0; i <= max_w; ++i) {
    cout << right << setw(2) << i << ' ';
  }
  cout << '\n';

  cout << "  | ";
  for (int i = 0; i <= max_w; ++i) {
    cout << right << setw(2) << (pos[i] ? "X": " ") << ' ';
  }
  cout << '\n';
}


int main()
{
  solve_1();
  cout << '\n';
  solve_2();
}