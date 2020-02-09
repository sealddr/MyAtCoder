#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<vector<ll>> gcds(2, vector<ll>(n - 1));
  rep(dir, 2) {
    gcds[dir][0] = a[0];
    rep(i, n - 2) {
      gcds[dir][i + 1] = gcd(gcds[dir][i], a[i + 1]);
    }
    if(dir == 0) reverse(all(a));
  }

  // ans = max(gcd({a[0], a[1], ..., a[n]} / {a[i]}) for
  // each a[i]
  ll ans = max(gcds[0][n - 2], gcds[1][n - 2]);
  for(int i = 1; i < n - 1; i++) {
    ans = max(ans, gcd(gcds[0][i - 1], gcds[1][n - i - 2]));
  }
  cout << ans << endl;
  return 0;
}