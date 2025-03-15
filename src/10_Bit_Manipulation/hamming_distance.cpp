#include <bits/stdc++.h>
using namespace std;


const int n = 10;
// bitstring size
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


// if __builtin_popcount is not available
int hamming_c_style(unsigned x, unsigned y)
{
    int dist = 0;

    // The ^ operators sets to 1 only the bits that are different
    for (unsigned val = x ^ y; val > 0; ++dist)
    {
        // We then count the bit set to 1 using the Peter Wegner way
        // ; // Set to zero val's lowest-order 1
        val = val & (val - 1);
    }

    // Return the number of differing bits
    return dist;
}


// O(nk)
vector<int> bitstrings_to_ints(const string* bitstr)
{
  vector<int> ints(n);
  for (int i = 0; i < n; ++i)
    ints[i] = std::stoi(bitstr[i], nullptr, 2);
  return ints;
}


// O(n^2)
void solve()
{
  vector<int> ints = bitstrings_to_ints(bitstr);
  // max possible
  int best = k;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int dist = __builtin_popcount(ints[i] ^ ints[j]);  // O(1)
      // int dist_c_style = hamming_c_style(ints[i], ints[j]);
      // assert(dist == dist_c_style);
      if (dist < best) best = dist;
    }
  }
  cout << "min Hamming distance: " << best << '\n';
}


int main() {solve();}
