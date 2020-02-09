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
  vector<double> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n) a[i] = 1.0 / a[i];
  double sum = 0;
  rep(i, n) sum += a[i];
  double ans = 1.0 / sum;
  printf("%.10f", ans);
  return 0;
}