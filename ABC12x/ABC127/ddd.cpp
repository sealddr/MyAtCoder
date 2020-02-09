#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n, m;
  cin >> n >> m;
  vector<P> op(n + m);
  rep(i, n) {
    int a;
    cin >> a;
    P p = make_pair(a, 1);
    op.push_back(p);
  }
  rep(j, m) {
    ll b, c;
    cin >> b >> c;
    P p = make_pair(c, b);
    op.push_back(p);
  }

  sort(all(op));
  reverse(all(op));
  
  ll updating = n;
  ll ans = 0;
  rep(j, n + m) {
    ll nb = min(updating, op[j].second);
    ans += nb * op[j].first;
    updating -= nb;
    if(updating < 0) break;
  }
  cout << ans << endl;
  return 0;
}