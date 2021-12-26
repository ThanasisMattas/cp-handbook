#include <bits/stdc++.h>
using namespace std;


const int n = 10;
const int k = 8;
stringstream input;
unsigned long arr[n];
// string bit_strings[n];


// O(k)
int hamming(string a, string b)
{
  int d = 0;
  for (int i = 0; i < k; ++i)
    if (a[i] != b[i]) ++d;
  return d;
}


// O(1)
int hamming(int a, int b)
{
  return __builtin_popcount(a ^ b);
}


int solve()
{
  int best = k;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      // int d = hamming(bit_string[i], bit_string[j]);
      int d = hamming(arr[i], arr[j]);
      best = min(best, d);
    }
  }
  return best;
}


void populate_input()
{
  string bstrs[n] = {"01110001",
                     "10100101",
                     "11101001",
                     "01001001",
                     "10101111",
                     "01100111",
                     "10111101",
                     "01010101",
                     "10110001",
                     "11111000"};

  for (int i = 0; i < n; ++i) {
    input << bstrs[i] << ' ';
  }
}


int main()
{
  populate_input();

  bitset<k> bset;
  for (int i = 0; i < n; ++i) {
    // cin >> bit_strings[i];
    input >> bset;
    arr[i] = bset.to_ulong();
  }

  cout << "min Hamming distance: " << solve() << '\n';
}
