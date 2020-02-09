#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll wsum = 0;
  rep(i, n) wsum += a[i];
  vector<ll> w(n);
  w[0] = wsum;
  for(int i = 1; i < n; i += 2) {
    w[0] -= 2 * a[i];
  }
  rep(i, n - 1) w[i + 1] = 2 * a[i] - w[i];
  rep(i, n) {
    printf("%lld%c", w[i], i == n - 1 ? '\n' : ' ');
  }
  return 0;
}