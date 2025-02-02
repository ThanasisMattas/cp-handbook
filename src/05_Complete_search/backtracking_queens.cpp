#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
  return out;
}


// diag1
// –––––
// y 3 | 3 4 5 6
//   2 | 2 3 4 5
//   1 | 1 2 3 4
//   0 | 0 1 2 3
//       – – – –
//       0 1 2 3
//             x

// diag2
// –––––
// y 3 | 6 5 4 3
//   2 | 5 4 3 2
//   1 | 4 3 2 1
//   0 | 3 2 1 0
//       – – – –
//       0 1 2 3
//             x


const int n = 4;
int counter = 0;
vector<int> column(n), diag1(2 * n - 1), diag2(2 * n - 1);


void solve(int y)
{
  // y is the row iterator. If y == n, then we've placed a queen at the last
  // row (n - 1) and we have a new solution.
  if (y == n) {
    ++counter;
    return;
  }
  // x is the column iterator
  for (int x = 0; x < n; ++x) {
    if (column[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
    column[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
    solve(y + 1);
    column[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
  }
}


int main()
{
  solve(0);
  cout << counter << endl;

  #ifdef DEBUG
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      cout << setw(2) << right << x + y << ' ';
    }
    cout << endl;
  }
  cout << '\n';
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      cout << setw(2) << right << x - y + n - 1 << ' ';
    }
    cout << endl;
  }
  #endif
}