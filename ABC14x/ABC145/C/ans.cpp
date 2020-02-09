#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<double, double> P;

double dl2(P a, P b) {
  double dx = a.first - b.first, dy = a.second - b.second;
  return sqrt(dx * dx + dy * dy);
}

int fact(int n) {
  if(n == 0)
    return 1;
  return n * fact(n - 1);
}

int main(void) {
  int n;
  cin >> n;
  vector<P> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  vector<vector<double>> d(n, vector<double>(n));
  rep(i, n) rep(j, n) d[i][j] = dl2(p[i], p[j]);
  vector<int> a(n);
  rep(i, n) a[i] = i;
  double ans = 0.0;
  do {
    rep(i, n - 1) {
      ans += d[a[i]][a[i + 1]];
    }
  } while(next_permutation(a.begin(), a.end()));
  ans /= fact(n);
  printf("%.10f\n", ans);
  return 0;
}