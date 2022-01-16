#include <bits/stdc++.h>
using namespace std;


const int n = 3;
int value[1 << n] = {3, 1, 4, 5, 5, 1, 3, 3};


// O(2^(2n))
void solve_brute_force()
{
  cout << "Brute Force: ";
  for (int g = 0; g < (1 << n); ++g) {
    int sum = 0;
    // all subsets of g are <= g
    for (int s = 0; s <= g; ++s) {
      // if s is subset of g
      if ((s & g) == s) sum += value[s];
    }
    cout << sum << ' ';
  }
  cout << '\n';
}



// We can only construct subsets of s by removing elements 0...k from s.
// sum[s] = partial(s, n - 1)
// partial(s, -1) = value[s]
// O(2^n)
int partial(int s, int k)
{
  if (k == -1) return value[s];
  if (s & (1 << k))
    return partial(s, k - 1) + partial(s ^ (1 << k), k - 1);
  else
    return partial(s, k - 1);
}


// O(2^(2n))
void solve_rec()
{
  cout << "Recursive: ";
  for (int s = 0; s < (1 << n); ++s) {
    cout << partial(s, n - 1) << ' ';
  }
  cout << '\n';
}


int sum[1 << n];


// O(n2^n)
void solve_dp()
{
  // initialize with value
  copy(value, value + (1 << n), sum);

  for (int k = 0; k < n; ++k)
    for (int s = 0; s < (1 << n); ++s)
      if (s & (1 << k)) sum[s] += sum[s ^ (1 << k)];

  cout << "DP: ";
  copy(sum, sum + (1 << n), ostream_iterator<int>(cout, " "));
  cout << '\n';
}


int main()
{
  solve_brute_force();
  solve_rec();
  solve_dp();
}