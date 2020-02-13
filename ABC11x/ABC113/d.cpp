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
ll dp[105][10];
int main() {
  int h, w, k;
  cin >> h >> w >> k;
  dp[0][1] = 1LL;
  auto lok = [&](int bm, int j) {
    if(j == 1) return false;
    if(!(bm & (1 << (j - 2)))) return false;
    return true;
  };
  auto rok = [&](int bm, int j) {
    bool res = true;
    if(j == w) return false;
    if(!(bm & (1 << (j - 1)))) return false;
    return true;
  };
  auto cok = [&](int bm, int j) {
    bool res = true;
    if(j != 1)
      if(bm & (1 << (j - 2))) return false;
    if(j != w)
      if(bm & (1 << (j - 1))) return false;
    return true;
  };

  for(int i = 1; i <= h; i++) {
    for(int j = 1; j <= w; j++) {
      rep(bm, (1 << (w - 1))) {
        bool ok = true;
        rep(k, w - 2) if(3 == ((bm >> k) & 3) % 4) ok =
          false;
        if(!ok) continue;
        if(lok(bm, j))
          dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
        if(rok(bm, j))
          dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
        if(cok(bm, j))
          dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
      }
    }
  }
  cout << dp[h][k] << endl;
  return 0;
}