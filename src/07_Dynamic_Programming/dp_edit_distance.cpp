#include <bits/stdc++.h>
using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) {
    copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
    cout << "\b\b";
  }
  return out;
}


template <typename T>
ostream& operator<<(ostream& out, const vector< vector<T> >& v)
{
  if (!v.empty()) {
    for (auto vec : v) out << "  " << vec << '\n';
  }
  return out;
}


const string x = "love";
const string y = "movie";
vector<vector<int> > dist(x.length() + 1,
                          vector<int>(y.length() + 1));


void print_distance_map()
{
  cout << "   ";
  for (auto c : y) cout << ' ' << c;
  cout << '\n';

  for (size_t i = 0; i <= x.length(); ++i) {
    if (i > 0) cout << x[i - 1] << ' ';
    else cout << "  ";

    for (size_t j = 0; j <= y.length(); ++j) {
      if (i == 0 && j == 0) dist[i][j] = 0;
      else if (i == 0) dist[i][j] = dist[i][j - 1] + 1;
      else if (j == 0) dist[i][j] = dist[i - 1][j] + 1;
      else dist[i][j] = min({dist[i][j - 1] + 1,
                             dist[i - 1][j] + 1,
                             dist[i - 1][j - 1] + (x[i - 1] != y[j - 1])});
      cout << dist[i][j] << ' ';
    }
    cout << '\n';
  }
}


int cost(int a, int b) {return x[a] == y[b] ? 0 : 1;}


int solve_recursive(int a, int b)
{
  if (a == 0 || b == 0) return a + b + cost(0, 0);
  return min({solve_recursive(a, b - 1) + 1,
              solve_recursive(a - 1, b) + 1,
              solve_recursive(a - 1, b - 1) + cost(a, b)});
}


// O(mn) ,  m, n the length of the strings
void solve_dp()
{
  vector<vector<int> > dist(x.length() + 1,
                            vector<int>(y.length() + 1));

  iota(dist[0].begin(), dist[0].end(), 0);
  int k = 0;
  for (vector<int>& v : dist) v[0] = k++;  // k++: first assign, then increment

  for (size_t i = 1; i <= x.length(); ++i)
    for (size_t j = 1; j <= y.length(); ++j)
      dist[i][j] = min({dist[i][j - 1] + 1,
                        dist[i - 1][j] + 1,
                        dist[i - 1][j - 1] + cost(i - 1, j - 1)});

  cout << "Edit distance: " << dist.back().back() << '\n';
}


int main()
{
  int a = x.length() - 1, b = y.length() - 1;
  cout << "Edit distance: " << solve_recursive(a, b) << '\n';
  solve_dp();
  cout << '\n';
  print_distance_map();
}