#include <bits/stdc++.h>
using namespace std;


// products
const int k = 3;
// days
const int n = 8;
int price[k][n] = {
  {6, 9, 5, 2, 8, 9, 1, 6},
  {8, 2, 6, 2, 7, 5, 7, 2},
  {5, 3, 9, 7, 3, 5, 1, 4}
};


// O(k^n)
int solve_rec(int s, int d)
{
  if (s == 0) return 0;
  if (d == 0) {
    // check if s is a power of 2 (namely, a single-item set)
    if ((s & (s - 1)) == 0) return price[(int)log2(s)][0];
    // s is a multy-item set, buy the cheapest product at day 0
    int best = INT_MAX;
    for (int x = 0; x < k; ++x) {
      // if x in s
      if (s & (1 << x)) best = min(best, price[x][0]);
    }
    return best;
  }

  // either we do not buy a product at day d
  int best = solve_rec(s, d - 1);
  // or buy a product x that belongs to s
  for (int x = 0; x < k; ++x) {
    if (s & (1 << x)) {
      // s ^ (1 << x) : remove x from s
      best = min(best, solve_rec(s ^ (1 << x), d - 1) + price[x][d]);
    }
  }
  return best;
}


// total[s][d]: min price of buying subset s at day d
int total[1 << k][n];


// O(nk2^k)
int solve_dp()
{
  // dp initialization
  // 0 total cost for empty subset at any day
  fill(total[0], total[0] + n, 0);
  // we can only pick one item at the 0th day
  for (int s = 1; s < (1 << k); ++s) {
    // if s is a single-item set
    // if (__builtin_popcount(s) == 1) {
    if ((s & (s - 1)) == 0) {
      total[s][0] = price[(int)log2(s)][0];
    } else {
      // if s is a multi-item set, buy the cheapest product at day 0
      int best = INT_MAX;
      for (int x = 0; x < k; ++x) {
        if (s & (1 << x)) best = min(best, price[x][0]);
      }
      total[s][0] = best;
    }
  }

  // rest of the days
  for (int d = 1; d < n; ++d) {
    for (int s = 1; s < (1 << k); ++s) {
      total[s][d] = total[s][d - 1];
      for (int x = 0; x < k; ++x) {
        // if x in s
        if (s & (1 << x)) {
          // s ^ (1 << x) : remove x from s
          total[s][d] = min(total[s][d],
                            total[s ^ (1 << x)][d - 1] + price[x][d]);
        }
      }
    }
  }
  return total[(1 << k) - 1][n - 1];
}


int main()
{
  int cost_rec = solve_rec((1 << k) - 1, n - 1);
  int cost_dp = solve_dp();
  cout << "total cost: " << cost_dp << '\n';
  assert(cost_rec == cost_dp);
}
