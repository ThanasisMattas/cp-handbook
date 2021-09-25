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


vector<int> arr{6, 2, 5, 1, 7, 4, 8, 3};
vector<int> len(arr.size(), 1);


void solve()
{
  int best = 1;

  for (size_t k = 0; k < arr.size(); ++k) {
    for (size_t i = 0; i < k; ++i) {
      if (arr[i] < arr[k]) {
        len[k] = max(len[k], len[i] + 1);
      }
    }
    best = max(best, len[k]);
  }
  cout << arr << '\n';
  cout << len << "\n";
  cout << best << "\n";
}


int main()
{
  solve();
}

