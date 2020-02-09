#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

const ll mod = 1000000007;
const int A = 0, C = 1, G = 2, T = 3;

const int MAXN = 105;
ll dp[MAXN][4][4][4];

int main() {
  int n;
  cin >> n;

  rep(j, 4) rep(k, 4) rep(l, 4) dp[3][j][k][l] = 1LL;
  dp[3][A][C][G] = 0LL;
  dp[3][G][A][C] = 0LL;
  dp[3][A][G][C] = 0LL;

  rep(len, n) {
    rep(i, 4) rep(j, 4) rep(k, 4) {
      if(dp[len][i][j][k] == 0) continue;
      for(int a : {A, G, C, T}) {
        if(j == A && k == G && a == C) continue;
        if(j == A && k == C && a == G) continue;
        if(j == G && k == A && a == C) continue;
        if(i == A && j == G && a == C) continue;
        if(i == A && k == G && a == C) continue;

        dp[len + 1][j][k][a] =
          (dp[len + 1][j][k][a] + dp[len][i][j][k]) % mod;
      }
    }
  }

  ll ans = 0;
  rep(j, 4) rep(k, 4) rep(l, 4) ans =
    (ans + dp[n][j][k][l]) % mod;
  cout << ans << endl;
  return 0;
}