#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MAX = 1e12 + 5;
int main(void) {
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n), f(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> f[i];
  sort(a.begin(), a.end());
  sort(f.begin(), f.end(), greater<int>());

  ll xl = -1, xr = MAX;
  while(xl + 1 < xr) {
    ll x = (xl + xr) / 2;
    ll sum = 0;
    rep(i, n) {
      if(x / f[i] < a[i]) {
        sum += a[i] - x / f[i];
      }
    }
    if(sum > k) {
      xl = x;
    } else {
      xr = x;
    }
  }
  cout << xr << endl;
  return 0;
}