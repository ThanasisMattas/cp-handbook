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

template <typename T>
ostream& operator<<(ostream& out, const deque<T>& v)
{
  out << '[';
  if (!v.empty()) {
    copy(v.begin(), v.end(), ostream_iterator<T>(out, ", "));
    cout << "\b\b";
  }
  out << ']';
  return out;
}

int arr[] = {2, 1, 4, 5, 3, 4, 1, 2};
int w = 4;

void solve_naive()
{
  int n = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i <= n - w; ++i) {
    cout << "min of window [ ";
    copy(arr + i, arr + i + w, ostream_iterator<int>(cout, " "));
    cout << "] is " << *min_element(arr + i, arr + i + w) << '\n';
  }
}


void solve()
{
  int n = sizeof(arr) / sizeof(arr[0]);
  deque<int> q;
  // init q
  for (int i = 0; i < w; ++i) {
    while (!q.empty() && q.back() >= arr[i]) q.pop_back();
    q.push_back(arr[i]);
  }

  cout << "min of window [ ";
  copy(arr, arr + w, ostream_iterator<int>(cout, " "));
  cout << "] with queue " << q << " is " << q.front() << '\n';

  for (int i = 1; i <= n - w; ++i) {
    // remove front if it falls out of the window
    if (q.front() == arr[i - 1]) q.pop_front();

    while(!q.empty() && q.back() >= arr[i + w - 1]) q.pop_back();
    q.push_back(arr[i + w - 1]);

    cout << "min of window [ ";
    copy(arr + i, arr + i + w, ostream_iterator<int>(cout, " "));
    cout << "] with queue " << q << " is " << q.front() << '\n';
  }
}


int main()
{
  solve();
}