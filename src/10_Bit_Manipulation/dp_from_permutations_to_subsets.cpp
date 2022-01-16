#include <bits/stdc++.h>
using namespace std;


const int x = 10;
const int n = 5;
int weight[n] = {2, 3, 3, 5, 6};
// <rides, last>
pair<int, int> best[1 << n];


// O(n2^n)
void solve()
{
  best[0] = make_pair(1, 0);

  for (int s = 1; s < (1 << n); ++s) {
    // initial value: n + 1 rides are needed
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