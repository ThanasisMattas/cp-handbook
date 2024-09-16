#include <bits/stdc++.h>
using namespace std;


const int n = 10;
const int k = 8;

string bitstr[n] = {
  "01110001",
  "10100101",
  "11101001",
  "01001001",
  "10101111",
  "01100111",
  "10111101",
  "01010101",
  "10110001",
  "11111000"
};


// O(k)
int hamming(string a, string b)
{
  int d = 0;
  for (int i = 0; i < k; ++i)
    if (a[i] != b[i]) ++d;
  return d;
}


// O(1)
int hamming(unsigned long a, unsigned long b)
{
  return __builtin_popcount(a ^ b);
}


void solve()
{
  // max possible
  int best = k;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int d = hamming(
        std::stoi(bitstr[i], nullptr, 2),  // probably O(k)
        std::stoi(bitstr[j], nullptr, 2)
      );
      best = min(best, d);
    }
  }
  cout << "min Hamming distance: " << best << '\n';
}


int main() {solve();}
