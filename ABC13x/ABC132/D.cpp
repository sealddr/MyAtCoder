#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
ll mod = 1000000007;
ll pow(ll b, ll e) {
  if(e == 0) return 1LL;
  if(e % 2 == 1) return pow(b, e - 1) * b % mod;
  ll m = pow(b, e >> 1);
  return m * m % mod;
}
ll inv(ll a) { return pow(a, mod - 2); }
int main(void) {
  int n, k;
  cin >> n >> k;
  vector<ll> fact(n + 1);
  fact[0] = 1LL;
  for(ll r = 1; r <= n; r++)
    fact[r] = fact[r - 1] * r % mod;
  ll ans = 0;
  for(ll i = 1; i <= k; i++) {
    ll a = n - k + 1;
    if(a < i) {
      puts("0");
      continue;
    }
    ans = fact[a] * inv(fact[i]) % mod;
    ans = ans * inv(fact[a - i]) % mod;

    ans = ans * fact[k - 1] % mod;
    ans = ans * inv(fact[i - 1]) % mod;
    ans = ans * inv(fact[k - i]) % mod;

    printf("%lld\n", ans);
  }
  return 0;
}