#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
const ll mod = 1000000007;

ll modfact(ll n) {
  ll res = 1LL;
  for(int i = 1; i <= n; i++) res = res * i % mod;
  return res;
}

ll modpow(ll b, ll e) {
  if(e == 0) return 1LL;
  if(e % 2 == 1) return modpow(b, e - 1) * b % mod;
  ll m = modpow(b, e >> 1);
  return m * m % mod;
}

ll inv(ll a) {
  return modpow(a, mod - 2);
}

int main() {
  ll n;
  ll x[2];
  cin >> n >> x[0] >> x[1];
  ll ans = modpow(2, n);
  rep(i, 2) {
    ll comb = 1LL;
    for(int r = 1; r <= x[i]; r++)
      comb = comb * (n - r + 1) % mod;
    comb = comb * inv(modfact(x[i])) % mod;
    ans = (ans + (mod - comb) % mod) % mod;
  }
  cout << --ans << endl;
  return 0;
}