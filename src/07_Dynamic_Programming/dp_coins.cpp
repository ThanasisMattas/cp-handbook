#pragma GCC optimize ("03")
#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
  return out;
}


vector<int> coins{2, 3, 4};
int dp[100000];
bool ready[100000];


int solve_recursive(int x)
{
  if (x < 0) return 2e9;
  if (x == 0) return 0;

  int best = 2e9;
  for (auto c : coins)
    best = min(best, solve_recursive(x - c) + 1);
  return best;
}


// O(xn),  x: value, n: num_coins
int solve_memoization_recursive(int x)
{
  if (x < 0) return 2e9;
  if (x == 0) return 0;
  if (ready[x]) return dp[x];

  int best = 2e9;
  for (auto c : coins)
    best = min(best, solve_memoization_recursive(x - c) + 1);
  dp[x] = best;
  ready[x] = true;
  return best;
}


// Same complexity with mem-rec, O(xn), but with smaller constants.
void solve_memoization_iterative(int x)
{
  for (int i = 1; i <= x; ++i) {
    for (auto c : coins) {
      if (i - c >= 0) {
        dp[i] = min(dp[i], dp[i - c] + 1);
      }
    }
  }
  cout << dp[x] << '\n';
}


// last coin to form the ith dp
int last[100000];


// O(xn)
void valid_solution(int x)
{
  for (int i = 1; i <= x; ++i) {
    for (auto c: coins) {
      if ((i - c >= 0) && (dp[i - c] + 1 < dp[i])) {
        dp[i] = dp[i - c] + 1;
        last[i] = c;
      }
    }
  }
  cout << dp[x] << '\n';

  int k = x;
  while (k) {
    cout << last[k] << ' ';
    k -= last[k];
  }
  cout << '\n';
}


// One solution for 0th value: 0 coins
int counter[100000] = {1};


// O(xn)
void count_solutions(int x)
{
  // coins: 2 3 4   n: 10

  // 2 2 3 3   2 2 2 4   2 4 4   4 3 3   2 2 2 2 2
  // 2 3 2 3   2 2 4 2   4 2 4   3 4 3
  // 2 3 3 2   2 4 2 2   4 4 2   3 3 4
  // 3 3 2 2   4 2 2 2
  // 3 2 3 2
  // 3 2 2 3
  for (int i = 1; i <= x; ++i) {
    for (auto c : coins) {
      if (i - c >= 0) {
        counter[i] += counter[i - c];
      }
    }
  }
  cout << counter[x] << '\n';
}


int main()
{
  int x = 10;
  cout << solve_recursive(x) << '\n';

  memset(dp, 0, sizeof(dp));
  cout << solve_memoization_recursive(x) << '\n';

  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  solve_memoization_iterative(x);

  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  valid_solution(x);

  count_solutions(x);
}
