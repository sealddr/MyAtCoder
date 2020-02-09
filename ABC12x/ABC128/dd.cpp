#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  rep(i, n) cin >> v[i];

  vector<ll> sl(n + 1);
  rep(i, n) sl[i + 1] = sl[i] + v[i];

  vector<int> rv(n);
  rep(i, n) rv[i] = v[i];
  reverse(all(rv));

  vector<ll> sr(n + 1);
  rep(i, n) sr[i + 1] = sr[i] + rv[i];

  ll ans = 0;
  rep(l, k + 1) rep(r, k - l + 1) {
    if(l + r > n) continue;
    int ret = k - l - r;
    vector<int> hand;
    rep(i, l) hand.push_back(v[i]);
    rep(i, r) hand.push_back(rv[i]);
    sort(all(hand));
    ll now = sl[l] + sr[r];
    rep(i, ret) {
      if(i >= hand.size()) break;
      if(hand[i] > 0) break;
      now -= hand[i];
    }
    ans = max(ans, now);
  }
  cout << ans << endl;

  return 0;
}