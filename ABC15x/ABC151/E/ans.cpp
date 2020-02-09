#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;
const ll mod = 1000000007;

ll pow(ll n, ll k) {
  if(k == 0) {
    return 1LL;
  }
  if(k % 2 == 1) {
    return pow(n, k - 1) * n % mod;
  }
  ll m = pow(n, k >> 1);
  return m * m % mod;
}

ll inv(ll n) {
  return pow(n, mod - 2);
}

int main(void) {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  if(k == 1) {
    cout << 0 << endl;
    return 0;
  }
  sort(a.begin(), a.end());
  ll max = 0, min = 0;
  ll comb = 1;
  rep(i, n - k + 1) {
    if(i != 0) {
      comb = (comb * (k - 1 + i)) % mod;
      comb = (comb * inv(i)) % mod;
    }
    int idxmin = n - k - i;
    ll pmin = a[idxmin] * comb % mod;
    min = (min + pmin) % mod;

    int idxmax = k - 1 + i;
    ll pmax = a[idxmax] * comb % mod;
    max = (max + pmax) % mod;
  }
  ll ans = (max - min) % mod;
  cout << ans << endl;
  return 0;
}