#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
const int MAXN = 100000;
const ll MAX = 2000000001;

int n;
vector<ll> a(MAXN);
vector<ll> w(MAXN);

ll f(ll sw) {
  w[0] = sw;
  for(int i = 0; i < n / 2; i++) {
    w[i + 1] = 2 * a[i] - w[i];
    w[n - i - 1] = 2 * a[(n - i - 1) % n] - w[(n - i) % n];
    if(w[i + 1] < 0 || w[n - i - 1] < 0)
      return 2 * (i % 2) - 1;
    if(i == (n - 3) / 2) {
      ll sub = 2 * a[i + 1] - (w[i + 1] + w[n - i - 1]);
      if(sub > 0) return 2 * (i % 2) - 1;
      if(sub < 0) return -2 * (i % 2) + 1;
    }
  }
  return 0;
}

int main(void) {
  cin >> n;
  a.resize(n);
  w.resize(n);
  rep(i, n) cin >> a[i];
  ll l = -1, r = MAX;
  while(r - l > 0) {
    ll mid = (l + r) / 2;
    if(f(mid) < 0) {
      r = mid;
    } else if(0 < f(mid)) {
      l = mid;
    } else {
      r = l = mid;
    }
  }
  rep(i, n) {
    printf("%lld%c", w[i], i == n - 1 ? '\n' : ' ');
  }
  return 0;
}