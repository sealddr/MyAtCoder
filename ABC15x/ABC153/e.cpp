#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
const int INF = 100000005;
const int MAXH = 10005;
int dp[MAXH];
int main() {
  int h, n;
  cin >> h >> n;
  vector<P> M(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    M[i] = make_pair(b, a);
  }
  sort(all(M));
  rep(i, h) dp[i] = INF;
  dp[h] = 0;
  rep(i, n) {
    for(int j = h; j >= 0; j--) {
      if(dp[j] == INF) continue;
      int now = max(0, j - M[i].second);
      dp[now] = min(dp[now], dp[j] + M[i].first);
    }
  }
  cout << dp[0] << endl;
  return 0;
}