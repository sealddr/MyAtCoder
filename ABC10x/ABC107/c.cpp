#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define dbg(x) cerr << #x << ": " << x << endl
const ll INF = 1001001001;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> X(n);
  rep(i, n) cin >> X[i];
  ll ans = INF;
  rep(i, n - k + 1) {
    int xfirst = X[i], xlast = X[i + k - 1];
    ll now =
      (ll)xlast - xfirst + min(abs(xfirst), abs(xlast));
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}