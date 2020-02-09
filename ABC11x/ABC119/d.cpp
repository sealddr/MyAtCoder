#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

const ll INF = 100000000005;
const int MAXN = 100001;
const int S = 0, T = 1;
const int FW = 1, BW = -1;
const int DIR[2] = {FW, BW};
const int SFW = 0, SBW = 1, TFW = 2, TBW = 3;
vector<vector<ll>> d(2, vector<ll>(MAXN));
int n[2];
ll bs(ll x, int st, int dir) {
  int oks[2] = {-1, n[st]};
  int ngs[2] = {n[st], -1};
  int ok = oks[dir], ng = ngs[dir];
  while(abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    if(DIR[dir] * (x - d[st][mid]) > 0)
      ok = mid;
    else
      ng = mid;
  }
  if(ng == (oks[dir] + DIR[dir])) return -DIR[dir] * INF;
  return d[st][ok];
}

int main() {
  int q;
  cin >> n[S] >> n[T] >> q;
  rep(st, 2) d[st].resize(n[st]);
  rep(i, n[S]) cin >> d[S][i];
  rep(j, n[T]) cin >> d[T][j];

  vector<ll> x(q);
  rep(k, q) cin >> x[k];

  rep(k, q) {
    ll nb[2][2];
    rep(st, 2) rep(dir, 2) {
      nb[st][dir] = bs(x[k], st, dir);
    }

    ll ans = INF;
    rep(sdir, 2) rep(tdir, 2) {
      ll d[2];
      d[0] = abs(nb[S][sdir] - x[k])
             + abs(nb[T][tdir] - nb[S][sdir]);
      d[1] = abs(nb[T][tdir] - x[k])
             + abs(nb[S][sdir] - nb[T][tdir]);
      rep(di, 2) ans = min(ans, d[di]);
    }
    cout << ans << endl;
  }

  return 0;
}