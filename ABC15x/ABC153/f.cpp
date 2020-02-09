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
  ll n, d, a;
  cin >> n >> d >> a;
  vector<P> M(n);

  rep(i, n) {
    ll x, h;
    cin >> x >> h;
    M[i] = make_pair(x, h);
  }
  sort(all(M));
  ll ans = 0;
  vector<ll> invalid(n + 1, 0);
  ll valid = 0;
  int j = 0;
  rep(i, n) {
    valid -= invalid[i];
    ll remain = M[i].second - valid * a;
    if(remain <= 0) continue;
    ll k = (remain + a - 1) / a;
    ans += k;
    valid += k;

    for(; abs(M[j].first - M[i].first) <= 2 * d && j < n;
        j++) {
    }
    invalid[j] += k;
  }
  cout << ans << endl;
  return 0;
}