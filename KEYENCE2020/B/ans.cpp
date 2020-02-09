#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Itv;
const ll INF = 1e9 + 5;
int main(void) {
  int n;
  cin >> n;
  vector<Itv> itvs(n);
  rep(i, n) {
    int x, l;
    cin >> x >> l;
    itvs[i] = make_pair(x + l, x - l);
  }
  sort(itvs.begin(), itvs.end());
  int ans = 0;
  ll t = -INF;
  rep(i, n) {
    if(t <= itvs[i].second) {
      ans++;
      t = itvs[i].first;
    }
  }
  cout << ans << endl;
  return 0;
}