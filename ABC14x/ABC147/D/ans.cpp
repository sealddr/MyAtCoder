#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;

const int mod = 1000000007;

int main(void) {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  rep(i, 64) {
    ll cnt = 0;
    rep(j, n) {
      if((a[j] & 1) == 0)
        cnt++;
      a[j] >>= 1;
    }
    ll p = (1LL << i) % mod;
    ll m = cnt * (n - cnt) % mod;
    ll d = m * p % mod;
    ans = (ans + d) % mod;
  }
  cout << ans << endl;
  return 0;
}