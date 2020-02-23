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
  ll N, K;
  cin >> N >> K;
  vector<int> fact;
  fact.push_back(1LL);
  for(ll i = 1; i <= N; i++)
    fact.push_back(i * fact[i - 1] % mod);
  K = min(N - 1, K);
  ll ans = 0LL;
  for(ll k = 0; k <= K; k++) {
    ll comb0 = fact[N] * inv(fact[k]) % mod;
    comb0 = comb0 * inv(fact[N - k]) % mod;

    ll comb1 = fact[N - 1] * inv(fact[k]) % mod;
    comb1 = comb1 * inv(fact[N - k - 1]) % mod;
    ll now = comb0 * comb1 % mod;
    ans = (ans + now) % mod;
  }
  cout << ans << endl;
  return 0;
}