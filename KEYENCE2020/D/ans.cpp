#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int main(void) {
  int n;
  cin >> n;
  vector<P> C(n);
  rep(i, n) cin >> C[i].first;
  rep(i, n) cin >> C[i].second;
  vector<int> a(n);
  int ans = 1e9;
  for(ll i = 0; i < (1LL << n); i++) {
    int cnt = 0;
    rep(j, n) {
      if((i >> j) & 1) {
        a[j] = C[i].first;
      } else {
        a[j] = C[i].second;
        ++cnt;
      }
    }
    if(cnt % 2) {
      continue;
    }
    int c = 0;
    rep(j, n) {
      rep(k, j) {
        if(a[k] > a[j])
          ++c;
      }
    }
    cout << c << ' ' << cnt << ' ' << ans << endl;
    if(c > 0) {
      c += 2;
      c -= cnt;
    }
    ans = min(ans, c);
  }
  cout << ans << endl;
  return 0;
}