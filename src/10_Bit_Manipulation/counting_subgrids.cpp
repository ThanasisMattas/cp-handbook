#include <bits/stdc++.h>
using namespace std;


const int n = 512;
const int N = 64;
int color[n][n];
long long color_bset[n][n / N];

// random_device rd;
// mersenne_twister_engine
mt19937_64 rng(time(nullptr));
// std::uniform_int_distribution<> distrib(1, 6);
uniform_int_distribution<long long> dist;


// O(n^3)
int brute_force()
{
  int total = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int count = 0;
      for (int k = 0; k < n; ++k) {
        if (color[i][k] && color[j][k]) ++count;
      }
      total += count * (count - 1) / 2;
    }
  }
  return total;
}


// O(n^3/N)
int bit_optimization()
{
  int total = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int count = 0;
      for (int k = 0; k < n / N; ++k) {
        count += __builtin_popcount(color_bset[i][k] & color_bset[j][k]);
      }
      total += count * (count - 1) / 2;
    }
  }
  return total;
}


int main()
{
  generate(color[0], color[0] + n * n, [](){return rand() % 2;});
  generate(color_bset[0], color_bset[0] + n * n / N, [](){return dist(rng);});

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cout << color[i][j] << ' ';

  cout << brute_force() << '\n';
  cout << bit_optimization() << '\n';
}
