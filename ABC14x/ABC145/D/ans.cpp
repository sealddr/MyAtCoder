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
ll mcomb(ll n, ll k) {
  ll res = 1LL;
  k = min(k, n - k);
  rep(i, k) res = res * (n - i) % mod;
  rep(i, k) res = res * inv(i + 1) % mod;
  return res;
}
const int MAX = 1000000;
int main(void) {
  ll x, y;
  cin >> x >> y;
  if((x + y) % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  ll n = (2 * y - x) / 3;
  ll m = (2 * x - y) / 3;
  if(n < 0 || m < 0) {
    cout << 0 << endl;
    return 0;
  }
  cout << mcomb(n + m, n) << endl;
  return 0;
}