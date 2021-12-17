#include <bits/stdc++.h>

using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  out << '[';
  if (!v.empty()) {
    copy(v.begin(), v.end(), ostream_iterator<T>(out, ", "));
    out << "\b\b";
  }
  out << ']';
  return out;
}


const int n = 8;
vector<int> v{6, 2, 5, 1, 7, 4, 8, 3};
vector<int> len(n, 1);


// O(n^2)
void solve()
{
  int best = 1;

  for (size_t k = 1; k < v.size(); ++k) {
    for (size_t i = 0; i < k; ++i) {
      if (v[i] < v[k]) {
        len[k] = max(len[k], len[i] + 1);
      }
    }
    best = max(best, len[k]);
  }
  cout << v << '\n';
  cout << len << "\n";
  cout << best << "\n";
}


vector<int> seq(n);

// O(nlogn)
void solve2()
{
  // points to the 1st empty slot in seq
  // (used to pre-alocate the memory of seq)
  int seq_len = 1;
  seq[0] = v[0];

  for (int k = 1; k < n; ++k) {
    auto it = lower_bound(seq.begin(), seq.begin() + seq_len, v[k]);
    if (it == seq.begin() + seq_len) seq[seq_len++] = v[k];
    else *it = v[k];
  }
  cout << seq_len << '\n';
}


int main() {solve2();}
