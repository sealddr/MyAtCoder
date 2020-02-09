#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
const double small = 1e-10;
int main(void) {
  int n, dim;
  cin >> n >> dim;
  vector<vector<int>> x(n, vector<int>(dim));
  rep(i, n) rep(d, dim) cin >> x[i][d];

  int ans = 0;
  rep(i, n) rep(j, n) {
    if(i >= j) continue;
    int sqd = 0;
    rep(d, dim) {
      int dx = x[i][d] - x[j][d];
      sqd += dx * dx;
    }
    int dist = sqrt(sqd) + small;
    if(dist * dist == sqd) ans++;
  }
  cout << ans << endl;
  return 0;
}