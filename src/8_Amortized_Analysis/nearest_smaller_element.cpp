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

// int arr[] = {1, 3, 4, 2, 5, 3, 4, 2};
int arr[] = {1, 3, 4, 2, 5, 3, 4, 0};


void solve()
{
  int n = sizeof(arr) / sizeof(arr[0]);
  stack<int> s;
  int sorted_until = distance(arr, is_sorted_until(arr, arr + n));

  s.push(arr[0]);
  for (int i = 1; i < sorted_until; ++i) {
    s.push(arr[i]);
    cout << "Nearest smaller of " << arr[i] << " is " << arr[i - 1] << '\n';
  }

  for (int i = sorted_until; i < n; ++i) {
    int top = s.top();
    bool possible = true;
    while (top >= arr[i]) {
      s.pop();
      if (s.empty()) {
        possible = false;
        break;
      }
      else top = s.top();
    }
    if (possible) cout << "Nearest smaller of " << arr[i] << " is " << top << '\n';
    else cout << "Nearest smaller of " << arr[i] << " is " << "IMPOSSIBLE" << '\n';
    s.push(arr[i]);
  }
}


int main()
{
  solve();
}