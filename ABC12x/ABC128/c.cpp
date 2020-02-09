#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> to(m, vector<int>(n));
  rep(i, m) {
    int k;
    cin >> k;
    rep(j, k) {
      int s;
      cin >> s;
      s--;
      to[i].push_back(s);
    }
  }
  vector<int> p(m);
  rep(i, m) cin >> p[i];
  int ans = 0;
  rep(bm, 1 << n) {
    bool ok = true;
    rep(i, m) {
      int cnt = 0;
      for(int j : to[i]) cnt += (bm >> j) & 1;
      if(cnt % 2 != p[i]) {
        ok = false;
        break;
      }
    }
    if(ok) ans++;
  }
  cout << ans << endl;
  return 0;
}