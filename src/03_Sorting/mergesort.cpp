#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include "../compete.hpp"
using namespace std;


vector<int> v{1, 3, 8, 2, 9, 5, 6};


void merge(int l, int m, int r)
{
  if ((l <= m) && (m <= r)) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1 + 1), R(n2 + 1);
    copy(v.begin() + l, v.begin() + m + 1, L.begin());
    copy(v.begin() + m + 1, v.begin() + r + 1, R.begin());
    L[n1] = std::numeric_limits<int>::max();
    R[n2] = std::numeric_limits<int>::max();
    int i = 0, j = 0;
    if (l != r) {
      for (int k = l; k <= r; ++k) {
        if (L[i] <= R[j]) {
          v[k] = L[i];
          ++i;
        } else {
          v[k] = R[j];
          ++j;
        }
      }
    }
  }
}


// O(nlogn)
void merge_sort(int l, int r)
{
  if (l < r) {
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    merge(l, m, r);
  }
}


void merge2(int l , int r, int m)
{
  int n1 = m - l + 1;
  int n2 = r - m;
  vector<int> v1(n1);
  vector<int> v2(n2);
  copy(v.begin() + l, v.begin() + m + 1, v1.begin());
  copy(v.begin() + m + 1, v.begin() + r + 1, v2.begin());
  int i = 0;
  int j = 0;
  int k = l;
  while ((i < n1) && (j < n2)) {
    if (v1[i] < v2[j]) {
      v[k] = v1[i];
      ++i;
    } else if (v1[i] > v2[j]) {
      v[k] = v2[j];
      ++j;
    } else {
      v[k] = v1[i];
      ++i;
      ++k;
      v[k] = v2[j];
      ++j;
    }
    ++k;
  }

  if (i < n1) copy(v1.begin() + i, v1.end(), v.begin() + k);
  else copy(v2.begin() + j, v2.end(), v.begin() + k);
}


void merge_sort2(int l , int r)
{
  if (l == r) return;
  if (r == l + 1) {
    if (v[r] < v[l]) swap(v[r], v[l]);
    return;
  }
  int m = (l + r) / 2;
  merge_sort2(l, m);
  merge_sort2(m + 1, r);
  merge2(l, r, m);
}


int main()
{
  cout << v << '\n';
  merge_sort2(0, v.size() - 1);
  cout << v << '\n';
}
