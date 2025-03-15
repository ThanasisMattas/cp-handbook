#include <bits/stdc++.h>
#include "../compete.hpp"
using namespace std;


const int n = 1500;
const int N = 64;
const int num_blocks = (n + N - 1) / N;
int color[n][n];
bitset<N> color_bset[n][num_blocks];

random_device rd;
// mersenne_twister_engine
mt19937_64 rng(rd());
uniform_int_distribution<int> dist(0, 1);


// O(n^3)
long long solve_brute_force()
{
  Timer t(__func__);

  long long total = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      long long count = 0;
      for (int k = 0; k < n; ++k) {
        if (color[i][k] && color[j][k]) ++count;
      }
      total += (count * (count - 1)) / 2;
    }
  }
  return total;
}


void compress_color_matrix()
{
  Timer t(__func__);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int block = j / N;
      int bit = j % N;
      color_bset[i][block][bit] = color[i][j];
    }
  }
}


// O(n^3/N)
long long bit_optimization()
{
  Timer t(__func__);

  long long total = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      long long count = 0;
      for (int k = 0; k < num_blocks; ++k) {
        // count += __builtin_popcount(color_bset[i][k] & color_bset[j][k]);
        count += (color_bset[i][k] & color_bset[j][k]).count();
      }
      total += (count * (count - 1)) / 2;
    }
  }
  return total;
}


int main()
{
  generate(color[0], color[0] + n * n, [](){return dist(rng);});

  long long count_solve_brute_force = solve_brute_force();
  compress_color_matrix();
  long long count_bit_optim = bit_optimization();

  assert(count_bit_optim == count_solve_brute_force);
  cout << "n=" << n << "  N=" << N << "  count=" << count_bit_optim << '\n';
}
