#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> x(m);
  rep(j, m) cin >> x[j];
  if(n >= m) {
    cout << 0 << endl;
    return 0;
  }
  sort(all(x));
  vector<int> intv(m - 1);
  rep(j, m - 1) intv[j] = x[j + 1] - x[j];
  sort(all(intv));
  reverse(all(intv));
  ll ans = 0LL;
  ans += (ll)x[m - 1];
  ans -= (ll)x[0];
  rep(i, n - 1) ans -= (ll)intv[i];
  cout << ans << endl;

  return 0;
}