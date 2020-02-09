#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(void) {
  int n, t;
  cin >> n >> t;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  vector<vector<int>> v(n + 1, vector<int>(t + 1));
  rep(j, t) v[0][j] = 0;
  vector<vector<int>> w(n + 1, vector<int>(t + 1));
  rep(j, t) w[0][j] = 0;

  rep(i, n) rep(j, t + 1) {
    if(a[i] > j) {
      v[i + 1][j] = v[i][j];
      if(j > 0) {
        w[i + 1][j] = max(w[i][j], v[i][j - 1] + b[i]);
      } else {
        w[i + 1][j] = w[i][j];
      }
    } else {
      v[i + 1][j] = max(v[i][j], v[i][j - a[i]] + b[i]);
      w[i + 1][j] = max(max(w[i][j], w[i][j - a[i]] + b[i]),
                        v[i][j - 1] + b[i]);
    }
  }
  cout << w[n][t] << endl;
  return 0;
}