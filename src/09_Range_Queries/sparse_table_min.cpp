#include <bits/stdc++.h>
using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
  return out;
}


vector<int> v{1, 3, 4, 8, 6, 1, 4, 2};
const int n = 8;
// Precalculated min queries sparse table.
//   - Each row intex corresponds to a power of 2.
//   - Each index of a row corresponds to the first limit of the subset, a.
//     The second limit is implied, b = a + w - 1.
//   - Each row item corresponds to the min_q(a, b).
vector<vector<int> > table;


// Uses sliding window minimum.
// nlog(n)
void populate_table()
{
  // number of rows of the sparse table
  int m = (int)log2(n);

  // 0th power of 2
  table.push_back(v);

  // 1st to m-th powers of 2
  for (int p = 1; p <= m; ++p) {
    // window length
    int w = 1 << p;
    vector<int> row(n - w + 1);
    queue<int> q;

    // 1st window
    for (int i = 0; i < w; ++i) {
      while ((!q.empty()) && (q.front() >= v[i])) q.pop();
      q.push(v[i]);
    }
    row[0] = q.front();

    // remaining windows
    for (int i = w; i < n; ++i) {
      // pop if front fell out of the window
      if (q.front() == v[i - w]) q.pop();
      while ((!q.empty()) && (q.front() >= v[i])) q.pop();
      q.push(v[i]);
      row[i - w + 1] = q.front();
    }

    table.push_back(row);
  }
}


// Uses bottom-up dp.
// nlog(n)
void populate_table_dp()
{
  // number of rows of the sparse table
  int m = (int)log2(n) + 1;

  // 0th power of 2
  table.push_back(v);

  // 1st-mth powers of 2
  for (int p = 1; p < m; ++p) {
    // window length
    int w = 1 << p;
    int row_len = n - w + 1;
    vector<int> row(row_len);

    for (int i = 0; i < row_len; ++i)
      row[i] = min(table.back()[i], table.back()[i + w / 2]);

    table.push_back(row);
  }
}


// nlog(n)
void print_table()
{
  for (int p = 0; p < table.size(); ++p) {
    for (int i = 0; i < table[p].size(); ++ i) {
      int w = 1 << p;
      cout << i << ' ' << i + w - 1 << ' ' << table[p][i] << '\n';
    }
    cout << '\n';
  }
}


// nlog(n) + q
void solve()
{
  // populate_table();
  populate_table_dp();
  print_table();
  cout << v << "\n\n";

  int q;
  int a, b;
  cout << "Number of queries: ";
  cin >> q;

  while (q--) {
    cout << "Subset limits: ";
    cin >> a >> b;

    // exponent of the largest power of 2 that is less than b - a + 1
    int p = (int)log2(b - a + 1);
    // window size
    int w = 1 << p;
    cout << min(table[p][a], table[p][b - w + 1]) << '\n';
  }
}


int main() {solve();}
