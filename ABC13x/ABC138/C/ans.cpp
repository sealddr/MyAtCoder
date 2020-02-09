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
  vector<double> v(n);
  rep(i, n) cin >> v[i];
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  double ans = 0.0;
  rep(i, n - 1) {
    double exp = (double)(1LL << (i + 1));
    ans += v[i] / exp;
  }
  ans += v[n - 1] / (double)(1LL << (n - 1));
  printf("%.10f", ans);
  return 0;
}