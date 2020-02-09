#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];

  vector<int> x, y, xp, yp;
  rep(i, h - 1) rep(j, w) {
    if(a[i][j] % 2) {
      a[i][j]--;
      a[i + 1][j]++;
      y.push_back(i + 1);
      x.push_back(j + 1);
      yp.push_back(i + 2);
      xp.push_back(j + 1);
    }
  }
  rep(j, w - 1) {
    if(a[h - 1][j] % 2) {
      a[h - 1][j]--;
      a[h - 1][j + 1]++;
      y.push_back(h);
      x.push_back(j + 1);
      yp.push_back(h);
      xp.push_back(j + 2);
    }
  }
  int n = y.size();
  cout << n << endl;
  rep(i, n) {
    cout << y[i] << ' ';
    cout << x[i] << ' ';
    cout << yp[i] << ' ';
    cout << xp[i] << endl;
  }
  return 0;
}