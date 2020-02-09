#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;

const ll mod = 1000000007;
ll pow(ll b, ll e) {
  if(e == 0)
    return 1LL;
  if(e % 2 == 1)
    return pow(b, e - 1) * b % mod;
  ll m = pow(b, e >> 1);
  return m * m % mod;
}

ll inv(ll a) {
  return pow(a, mod - 2);
}

int main(void) {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<ll> fact(n + 1);
  rep(i, n + 1) {
    if(i == 0) {
      fact[i] = 1LL;
      continue;
    }
    fact[i] = fact[i - 1] * i % mod;
  }
  vector<ll> ifact(n + 1);
  rep(i, n + 1) {
    if(i == 0) {
      ifact[i] = 1LL;
      continue;
    }
    ifact[i] = ifact[i - 1] * inv(i) % mod;
  }
  sort(a.begin(), a.end());
  ll smin = 0;
  ll smax = 0;
  rep(i, n - k + 1) {
    ll comb = fact[n - 1 - i] * ifact[k - 1] % mod;
    comb = comb * ifact[n - i - k] % mod;
    ll min = a[i] * comb % mod;
    smin = (smin + min) % mod;
    ll max = a[n - 1 - i] * comb % mod;
    smax = (smax + max) % mod;
  }
  ll ans = (smax - smin) % mod;
  ans = (ans + mod) % mod;
  cout << ans << endl;

  return 0;
}