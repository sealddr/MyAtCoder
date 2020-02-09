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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0L;
  ll ss = 0L;
  int j = 0;
  rep(i, n) {
    while(ss < k) {
      if(j == n)
        break;
      else {
        ss += a[j];
        j++;
      }
    }
    if(ss < k) break;
    ans += n - j + 1;
    ss -= a[i];
  }
  cout << ans << endl;
  return 0;
}