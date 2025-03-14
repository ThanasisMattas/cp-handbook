#pragma GCC optimize ("03")
#include <bits/stdc++.h>
#include "../compete.hpp"
using namespace std;


const int n = 8000;
vector<int> v(n);  // {6, 2, 5, 7, 4, 8, 3};

// uncomment all comments for explanation
// vector<int> v{6, 2, 5, 1, 7, 4, 8, 3};
// const int n = v.size();

vector<int> len(n, 1);


// O(n^2)
void solve1()
{
  Timer t(__func__);

  int best = 1;

  for (int k = 1; k < n; ++k) {
    for (int i = 0; i < k; ++i)
      if (v[i] < v[k])
        len[k] = max(len[k], len[i] + 1);
    best = max(best, len[k]);
  }
  cout << best << '\n';
}

// Holds the LIS, but it won’t necessarily store the exact sequence, just the
// values that could form the LIS. The last part of this vector will be popu-
// lated with the last items of the current LIS, whereas the first part will
// start bulding a prospect LIS that will potentially overthrow the current.
vector<int> seq(n);


// O(nlogn)
// (maybe too advanced for CP)
void solve2()
{
  Timer t(__func__);

  // length of the populated part of the sequence
  int seq_len = 1;
  seq[0] = v[0];

  for (int k = 1; k < n; ++k) {
    auto it = lower_bound(seq.begin(), seq.begin() + seq_len, v[k]);
    // cout << v[k] << ' ' << seq_len << ' ' << distance(seq.begin(), it) << '\n';
    if (it == seq.begin() + seq_len) seq[seq_len++] = v[k];
    else *it = v[k];
    // cout << seq << '\n';
  }
  cout << seq_len << '\n';
}


int main() {
  iota(v.begin(), v.end(), 0);
  shuffle(v.begin(), v.end(), default_random_engine());
  solve1();
  solve2();
}
