#include <bits/stdc++.h>
using namespace std;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef vector<pair<int, int> > vpi;

// (a +/-/* b) % mod = (a % mod +/-/* b % mod) % mod
// (a / b) % mod = (a * pow(b, mod - 2, mod)) % mod
#define mod (ll)(1e9 + 7);

#define B begin()
#define E end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define LP(i,a,b) for (int i = a; i < b; ++i)
#define lp(i,b) for (int i = 0; i < b; ++i)

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) copy(v.B, v.E, ostream_iterator<T>(out, " "));
  return out;
}


void solve()
{

}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
