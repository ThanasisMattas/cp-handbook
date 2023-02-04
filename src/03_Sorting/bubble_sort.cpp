#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
  return out;
}


vector<int> v{-1, 2, 4, -3, 5, 2, -5, 2};


void bubble_sort()
{
  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (int i = 0; i < v.size() - 1; ++i)
      if (v[i] > v[i + 1]) {
        swap(v[i], v[i + 1]);
        swapped = true;
      }
  }
}


// O(n^2)
int main()
{
  for (int i = 0; i < v.size(); ++i)
    for (int j = 0; j < v.size() - 1; ++j)
      if (v[j] > v[j + 1])
        swap(v[j], v[j + 1]);

  cout << v << '\n';
}
