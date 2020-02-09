#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;
  vector<int> x(n + 1);
  rep(i, n) cin >> x[i];
  x[n] = X;
  vector<int> y(m + 1);
  rep(i, m) cin >> y[i];
  y[m] = Y;
  int xmax = -999;
  rep(i, n + 1) xmax = max(xmax, x[i]);
  int ymin = 999;
  rep(i, m + 1) ymin = min(ymin, y[i]);
  if(xmax >= ymin) {
    cout << "War" << endl;
    return 0;
  }
  cout << "No War" << endl;
  return 0;
}