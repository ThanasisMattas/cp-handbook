#include <bits/stdc++.h>

using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  out << '[';
  if (!v.empty()) {
    copy(v.begin(), v.end(), ostream_iterator<T>(out, ", "));
    cout << "\b\b";
  }
  out << ']';
  return out;
}

int arr[] = {1, 3, 2, 5, 1, 1, 2, 3};
int x = 8;

void solve()
{
  int n = sizeof(arr) / sizeof(arr[0]);
  int* l = arr;
  int* r = arr + 1;
  int sum = 0;

  while ((distance(l, r) >= 0) && (distance(arr, r) <= n)) {
    if (sum == x) {
      copy(l, r, ostream_iterator<int>(cout, " "));
      cout << '\n';
      return;
    }
    else if ((sum < x) && (accumulate(l, r + 1, 0) <= x)) r += 1;
    else l += 1;
    sum = accumulate(l, r, 0);
  }
  cout << "IMPOSSIBLE\n";
}


int main()
{
  solve();
}
