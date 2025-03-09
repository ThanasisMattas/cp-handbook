#include<bits/stdc++.h>
#include "../compete.hpp"
using namespace std;

vector<int> v{-1, 2, 4, -3, 5, 2, -5, 2};


// O(n)
void solve()
{
  int sum = 0;
  int best = -1e9;
  for (auto i : v) {
    sum = max(sum + i, i);
    best = max(best, sum);
  }
  cout << best << '\n';
}


// O(n)
void max_subarray()
{
  int sum = 0;
  int best = -1e9;
  vector<int> sub;
  vector<int> best_sub;

  for (int& x : v) {
    sum += x;
    if (x > sum) {
      sum = x;
      sub.clear();
      sub.push_back(x);
    } else sub.push_back(x);
    // cout << setw(2) << x << ' '
    //      << setw(2) << sum << ' ';
    // cout << sub << '\n';

    if (sum > best) {
      best = sum;
      best_sub = sub;
    }
  }

  cout << best << '\n';
  cout << best_sub << '\n';
}

int main() {max_subarray();}
