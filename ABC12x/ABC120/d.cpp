#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  ll n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }

  vector<vector<int>> V(n);
  rep(j, n) V[j].push_back(j);
  vector<int> idx(n);
  rep(j, n) idx[j] = j;

  ll cnt =
    n * (n - 1) / 2;    // take care not to be overflow
  vector<ll> ans;
  ans.push_back(cnt);

  reverse(all(a));
  reverse(all(b));

  rep(i, m - 1) {
    int aj = idx[a[i]], bj = idx[b[i]];
    if(aj == bj) {
      ans.push_back(cnt);
      continue;
    }

    ll sza = (ll)V[aj].size(), szb = (ll)V[bj].size();
    cnt -= sza * szb;
    ans.push_back(cnt);

    if(sza < szb) swap(aj, bj);
    for(auto x : V[bj]) {
      V[aj].push_back(x);
      idx[x] = aj;
    }
    V[bj].clear();
  }

  reverse(all(ans));
  rep(i, m) printf("%lld\n", ans[i]);
  return 0;
}
