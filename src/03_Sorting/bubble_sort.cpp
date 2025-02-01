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


// O(n^2)
void bubble_sort_1()
{
  for (int i = 0; i < v.size(); ++i)
    for (int j = 0; j < v.size() - 1; ++j)
      if (v[j] > v[j + 1])
        swap(v[j], v[j + 1]);
}


// The nested loop is condemned to run to the end, even if the array is
// sorted sooner. With the following impl, the outer loop breaks if no
// more swaps are possible, meaning that the array is already sorted.
void bubble_sort_2()
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


int main()
{
  cout << v << '\n';
  bubble_sort_2();
  cout << v << '\n';
}
