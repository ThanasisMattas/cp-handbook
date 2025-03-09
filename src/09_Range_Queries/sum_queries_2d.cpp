#include <bits/stdc++.h>
#include "../compete.hpp"
using namespace std;


const int n = 5;
vector<vector<int> > v(n, vector<int>(n));
// prefix sum matrix
vector<vector<int> > psm(n, vector<int>(n));
// bottom-right & top-left coordinates
int x_br, y_br, x_tl, y_tl;


template <int x=10>
int rand_int() {return rand() % x;}


// O(n^2) (linear with the input size)
void populate_psm()
{
  // populate the first row
  partial_sum(v[0].begin(), v[0].end(), psm[0].begin());
  // populate the first column
  for (int i = 1; i < n; ++i)
    psm[i][0] = psm[i - 1][0] + v[i][0];
  // populate the rest
  for (int i = 1; i < n; ++i)
    for (int j = 1; j < n; ++j)
      psm[i][j] = psm[i - 1][j] + psm[i][j - 1] - psm[i - 1][j - 1] + v[i][j];
}


// O(1)
void solve()
{
  int a = psm[y_br][x_br];
  if (x_tl) a -= psm[y_br][x_tl - 1];
  if (y_tl) a -= psm[y_tl - 1][x_br];
  if (x_tl && y_tl) a += psm[y_tl - 1][x_tl - 1];
  cout << "Submatrix sum: " << a << '\n';
}


int main()
{
  // Populate the matrix with random integers in [0-10)
  for (vector<int>& ve : v) generate(ve.begin(), ve.end(), rand_int<10>);
  // Populate the prefix sum matrix
  populate_psm();

  cout << v << '\n';

  cout << "Insert bot right coords (x y): ";
  cin >> x_br >> y_br;
  cout << "Insert top left coords (x y): ";
  cin >> x_tl >> y_tl;

  solve();
}
