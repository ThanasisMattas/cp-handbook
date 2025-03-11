#include <bits/stdc++.h>
using namespace std;


const string x = "love";
const string y = "movie";


//  O(3^min(n, m))
int solve_recursive(int a, int b)
{
  if (a == 0 || b == 0) return a + b + (int)(x[0] != y[0]);
  return min({solve_recursive(a, b - 1) + 1,
              solve_recursive(a - 1, b) + 1,
              solve_recursive(a - 1, b - 1) + (int)(x[a] != y[b])});
}


// O(nm)
void solve()
{
  const int n = x.length();
  const int m = y.length();
  int dist[n + 1][m + 1];
  memset(dist, 0, sizeof(dist));

  for (int i = 1; i <= n; ++i) dist[i][0] = i;
  for (int j = 1; j <= m; ++j) dist[0][j] = j;

  // Optional printing block:
  cout << "    ";
  for (int i = 0; i < m; ++i) cout << y[i] << ' ';
  cout << '\n';
  cout << "  ";
  for (int i = 0; i <= m; ++i) cout << dist[0][i] << ' ';
  cout << '\n';

  for (int i = 1; i <= n; ++i) {
    cout << x[i - 1] << ' ' << dist[i][0] << ' ';
    for (int j = 1; j <= m; ++j) {
      dist[i][j] = min(
        {
          dist[i][j - 1] + 1,
          dist[i - 1][j] + 1,
          dist[i - 1][j - 1] + (int)(x[i - 1] != y[j - 1])
        }
      );
      cout << dist[i][j] << ' ';
    }
    cout << '\n';
  }
}


int main()
{
  cout << "Edit distance (recursive): "
       << solve_recursive(x.length() - 1, y.length() - 1)
       << "\n\n"
       << "Iterative:\n";
  solve();
}
