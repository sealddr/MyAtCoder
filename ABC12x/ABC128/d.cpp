#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
const int MAXN = 52;
const ll INF = 10000000005;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  rep(i, n) cin >> v[i];

  vector<ll> sl(n + 1);
  rep(i, n) sl[i + 1] = sl[i] + v[i];

  reverse(all(v));
  vector<int> rv(n);
  rep(i, n) rv[i] = v[i];
  reverse(all(v));

  vector<ll> sr(n + 1);
  rep(i, n) sr[i + 1] = sr[i] + rv[i];

  vector<vector<vector<ll>>> retv(
    n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1)));
  vector<int> L, R;
  priority_queue<int, vector<int>, greater<int>> H;
  rep(l, n + 1) {
    R.clear();
    rep(r, n + 1) {
      while(H.size()) H.pop();
      for(auto vr : R) H.emplace(vr);
      for(auto vl : L) H.emplace(vl);
      rep(ret, n + 1) {
        if(ret == 0) continue;
        if(l + r < ret) {
          retv[l][r][ret] = INF;
          continue;
        }
        if(l + r > n) {
          retv[l][r][ret] = INF;
          continue;
        }
        int x = H.top();
        H.pop();
        retv[l][r][ret] = retv[l][r][ret - 1] + x;
      }
      if(r < n) R.push_back(rv[r]);
    }
    if(l < n) L.push_back(v[l]);
  }
  ll ans = 0;
  rep(l, n + 1) rep(r, n + 1) rep(h, n + 1) {
    int ret = l + r - h;
    if(l + r + ret > k) continue;
    if(l + r < h) continue;
    if(l + r > n) continue;

    ll now = sl[l] + sr[r] - retv[l][r][ret];
    ans = max(ans, now);
  }
  cout << ans << endl;

  return 0;
}