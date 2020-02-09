#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  double ans = 0.0;
  auto E = [&](int x) { return (double)(x + 1) / 2; };
  rep(i, k) ans += E(p[i]);
  double now = ans;
  for(int i = 0; i + k < n; i++) {
    now += E(p[i + k]) - E(p[i]);
    ans = max(ans, now);
  }
  printf("%.10f\n", ans);
  return 0;
}