#include <bits/stdc++.h>
using namespace std;


const int x = 10;
const int n = 5;
int weight[n] = {2, 3, 3, 5, 6};
// <num_rides, last_sum>
pair<int, int> best[1 << n];


// O(n2^n)
void solve()
{
  // Why not {0, 0}?
  // Because we will start building the 1st ride, by adding weights to second.
  // We can of course check if first is 0 and add 1, when building the 1st
  // ride, but it is simpler this way.
  best[0] = make_pair(1, 0);

  for (int s = 1; s < (1 << n); ++s) {
    // worst possible value: n + 1 rides
    best[s] = make_pair(n + 1, 0);
    for (int p = 0; p < n; ++p) {
      if (s & (1 << p)) {
        auto option = best[s ^ (1 << p)];
        if (option.second + weight[p] <= x) {
          // add p to an existing ride
          option.second += weight[p];
        } else {
          // reserve a new ride for p
          ++option.first;
          option.second = weight[p];
        }
        best[s] = min(best[s], option);
      }
    }
  }
  cout << best[(1 << n) - 1].first << '\n';
}


int main() {solve();}