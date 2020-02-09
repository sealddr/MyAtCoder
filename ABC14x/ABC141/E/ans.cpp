#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main(void) {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int dp[n + 1][n + 1];
  rep(i, n + 1) dp[i][n] = 0;
  rep(j, n + 1) dp[n][j] = 0;

  rep(i, n) rep(j, n) {
    int ii = n - i - 1;
    int jj = n - j - 1;
    if(s[ii] == s[jj])
      dp[ii][jj] = dp[ii + 1][jj + 1] + 1;
    else
      dp[ii][jj] = 0;
  }
  int ans = 0;
  rep(i, n) rep(j, i) {
    int now = min(i - j, dp[i][j]);
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}