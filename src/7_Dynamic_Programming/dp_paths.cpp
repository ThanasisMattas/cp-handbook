#include <bits/stdc++.h>

using namespace std;


const int n = 5;
int value[n + 1][n + 1] = {{0, 0, 0, 0, 0, 0},
                           {0, 3, 7, 9, 2, 7},
                           {0, 9, 8, 3, 5, 5},
                           {0, 1, 7, 9, 8, 5},
                           {0, 3, 8, 6, 4, 10},
                           {0, 6, 3, 9, 7, 8}};
int sum[n + 1][n + 1];


// O(n^2)
void solve()
{
  memset(sum, 0, sizeof(sum));

  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <=n; ++x) {
      sum[y][x] = max(sum[y][x - 1], sum[y - 1][x]) + value[y][x];
    }
  }
  cout << sum[n][n] << endl;
}


int main()
{
  solve();
}
