#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
const ll mod = 2019;
int main(void) {
  ll L, R;
  cin >> L >> R;
  if(R - L >= mod) {
    cout << 0 << endl;
    return 0;
  }
  int ans = mod;
  for(ll i = L; i <= R - 1; i++) {
    for(ll j = L + 1; j <= R; j++) {
      if(i >= j) continue;
      int now = (i * j) % mod;
      ans = min(ans, now);
    }
  }
  cout << ans << endl;
  return 0;
}