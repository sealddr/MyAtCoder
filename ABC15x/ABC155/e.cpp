#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define dbg(x) cerr << #x << ": " << x << endl
#define all(x) (x).begin(), (x).end()

int dp[1000100][2];
const int INF = 1000000005;
int main() {
  string s;
  cin >> s;
  reverse(all(s));
  s += '0';
  int m = s.size();
  rep(i, m + 1) rep(j, 2) dp[i][j] = INF;
  dp[0][0] = 0;
  rep(i, m) rep(j, 2) {
    int n = s[i] - '0';
    n += j;
    rep(a, 10) {
      int ni = i + 1, nj = (a - n < 0);
      int b = a - n >= 0 ? a - n : 10 + a - n;
      dp[ni][nj] = min(dp[ni][nj], dp[i][j] + a + b);
    }
  }
  cout << dp[m][0] << endl;
  return 0;
}