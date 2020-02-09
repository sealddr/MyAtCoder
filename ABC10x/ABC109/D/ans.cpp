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
  rep(i, h) rep(j, w) {
    int jj = j;
    int vec = 1;
    if(i % 2) {
      jj = w - j - 1;
      vec = -1;
    }
    if(j == w - 1) {
      if(i == h - 1) continue;
      if(a[i][jj] % 2) {
        a[i][jj]--;
        a[i + 1][jj]++;
        y.push_back(i + 1);
        x.push_back(jj + 1);
        yp.push_back(i + 2);
        xp.push_back(jj + 1);
      }
    } else if(a[i][jj] % 2) {
      a[i][jj]--;
      a[i][jj + vec]++;
      y.push_back(i + 1);
      x.push_back(jj + 1);
      yp.push_back(i + 1);
      xp.push_back(jj + vec + 1);
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