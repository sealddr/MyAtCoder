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
int main() {
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<P> v(a + b + c);
  rep(i, a) {
    int p;
    cin >> p;
    v[i] = make_pair(p, 0);
  }
  rep(i, b) {
    int q;
    cin >> q;
    v[a + i] = make_pair(q, 1);
  }
  rep(i, c) {
    int r;
    cin >> r;
    v[a + b + i] = make_pair(r, 2);
  }
  sort(all(v));
  reverse(all(v));
  int cnt[3] = {0, 0, 0};
  int n = v.size();
  ll ans = 0;
  rep(i, n) {
    if(0 == v[i].second && x == cnt[0]) continue;
    if(1 == v[i].second && y == cnt[1]) continue;
    ++cnt[v[i].second];
    ans += (ll)v[i].first;
    if(cnt[0] + cnt[1] + cnt[2] >= x + y) break;
  }
  cout << ans << endl;
  return 0;
}