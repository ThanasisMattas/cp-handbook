#pragma GCC optimize ("03")
#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
  return out;
}

struct Timer
{
  chrono::high_resolution_clock::time_point start, end;
  string name;

  Timer(string n="")
  : start(chrono::high_resolution_clock::now()), name(n) {}

  ~Timer()
  {
    chrono::duration<float> d = chrono::high_resolution_clock::now() - start;
    cout << name
         << string(int(!name.empty()), ' ')
         << "duration: "
         << (d.count() * 1000.0f)
         << '\n';
  }
};


const int n = 8000;
vector<int> v(n);  // {6, 2, 5, 7, 4, 8, 3};
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


vector<int> seq(n);


// O(nlogn)
void solve2()
{
  Timer t(__func__);

  // uncomment all comments for explanation
  // vector<int> v{6, 2, 5, 1, 7, 4, 8, 3};
  // const int n = 8;
  // vector<int> seq(n);
  // cout << v << '\n';
  // cout << seq << '\n';

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
  random_shuffle(v.begin(), v.end());
  solve1();
  solve2();
}
