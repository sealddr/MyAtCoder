#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

const ll INF = 100000000005;
int main() {
  int a, b, q;
  cin >> a >> b >> q;

  vector<ll> S, T;
  S.push_back(-INF);
  T.push_back(-INF);
  rep(i, a) {
    ll s;
    cin >> s;
    S.push_back(s);
  }
  rep(j, b) {
    ll t;
    cin >> t;
    T.push_back(t);
  }
  S.push_back(INF);
  T.push_back(INF);

  vector<ll> x(q);
  rep(k, q) cin >> x[k];

  rep(k, q) {
    auto ubs = upper_bound(all(S), x[k]);
    auto ubt = upper_bound(all(T), x[k]);

    ll ans = INF;
    for(ll s : {*(ubs - 1), *ubs})
      for(ll t : {*(ubt - 1), *ubt}) {
        ll D[2] = {abs(s - x[k]) + abs(t - s),
                   abs(t - x[k]) + abs(s - t)};
        for(ll d : D) ans = min(ans, d);
      }
    cout << ans << endl;
  }
  return 0;
}