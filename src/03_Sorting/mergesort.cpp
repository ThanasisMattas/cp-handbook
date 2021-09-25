#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>

using namespace std;
using vi = vector<int>;


ostream& operator<<(ostream& out, const vi& v)
{
  out << '[';
  if (!v.empty()) {
    copy(v.begin(), v.end(), ostream_iterator<int>(out, ", "));
    out << "\b\b";
  }
  out << ']';
  return out;
}


void merge(vi& v, int l, int m, int r)
{
  if (l <= m && m <= r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vi L(n1 + 1), R(n2 + 1);
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
void merge_sort(vi& v, int l, int r)
{
  if (l < r) {
    int m = (l + r) / 2;
    merge_sort(v, l, m);
    merge_sort(v, m + 1, r);
    merge(v, l, m, r);
  }
}


int main()
{
  vi v{1, 3, 8, 2, 9, 5, 6};
  cout << v << endl;

  merge_sort(v, 0, v.size() - 1);
  if (is_sorted(v.begin(), v.end()))
    cout << "Sorted:\n" << v << '\n';
}
