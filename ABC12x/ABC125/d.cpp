#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n;
  cin >> n;
  vector<ll> b(n);
  int flg = 0;
  int k = 0;
  rep(i, n) {
    ll a;
    cin >> a;
    if(a < 0) flg ^= 1;
    b[i] = abs(a);
    if(b[k] > b[i]) k = i;
  }

  b[k] *= 1 - 2 * flg;
  ll ans = 0LL;
  rep(i, n) ans += b[i];
  cout << ans << endl;
  return 0;
}