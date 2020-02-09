#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
const int INF = 1000000005;

int main() {
  int h, n;
  cin >> h >> n;
  vector<int> dp(h + 1, INF);
  dp[0] = 0;

  rep(i, n) {
    int a, b;
    cin >> a >> b;
    rep(j, h) {
      int now = min(h, j + a);
      dp[now] = min(dp[now], dp[j] + b);
    }
  }
  cout << dp[h] << endl;
  return 0;
}