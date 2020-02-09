#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int n;
  cin >> n;
  vector<ll> a(n + 1), b(n);
  rep(i, n + 1) cin >> a[i];
  rep(i, n) cin >> b[i];
  ll ans = 0;
  rep(i, n) {
    ll toubatsu = min(a[i], b[i]);
    ans += toubatsu;
    b[i] -= toubatsu;
    toubatsu = min(a[i + 1], b[i]);
    ans += toubatsu;
    a[i + 1] -= toubatsu;
  }
  cout << ans << endl;
  return 0;
}