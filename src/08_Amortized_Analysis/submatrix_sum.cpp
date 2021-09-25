#include<bits/stdc++.h>

using namespace std;


const int r = 4, c = 5;
int mat[r][c] = {{1, 2, 3, 4, 6},
                 {5, 3, 8, 1, 2},
                 {4, 6, 7, 5, 5},
                 {2, 4, 8, 9, 4}};
int cumsum_mat[r][c];


int solve(int ul_row, // upper left
          int ul_col,
          int lr_row, // lower right
          int lr_col)
{
  // cumsum row-wise
  for (int i = 0; i < r; ++i) {
    partial_sum(mat[i], mat[i] + c, cumsum_mat[i]);
  }
  // cumsum colum-wise
  for (int j = 0; j < c; ++j) {
    for (int i = 1; i < r; ++i) {
      cumsum_mat[i][j] += cumsum_mat[i - 1][j];
    }
  }

  // Print the matrix.
  //
  // for (int i = 0; i < r; ++i) {
  //   for (int j = 0; j < c; ++j) {
  //     cout << cumsum_mat[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  // for (int i = 0; i < r; ++i) {
  //   for (int j = 0; j < c; ++j) {
  //     cout << mat[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  int result = cumsum_mat[lr_row][lr_col];
  if (ul_col > 0)
    result -= cumsum_mat[lr_row][ul_col - 1];
  if (ul_row > 0)
    result -= cumsum_mat[ul_row - 1][lr_col];
  if (ul_row > 0 && ul_col >= 0)
    result += cumsum_mat[ul_row - 1][ul_col - 1];
  return result;
}


int main()
{
  assert(solve(0, 0 , 1, 1) == 11);
  assert(solve(1, 2, 3, 3) == 38);
  assert(solve(2, 2, 3, 4) == 38);
}
