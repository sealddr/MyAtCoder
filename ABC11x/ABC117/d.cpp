#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  ll x = 0LL;
  int keta = 0;
  while((k >> keta) > 0) keta++;
  while(keta > 0) {
    keta--;    // 0-base indexing
    int cnt1 = 0;
    rep(i, n) if((A[i] >> keta) & 1) cnt1++;
    if(cnt1 < n / 2 + 1 && x + (1LL << keta) <= k)
      x += (1LL << keta);
  }
  ll ans = 0LL;
  rep(i, n) ans += A[i] ^ x;
  cout << ans << endl;
  return 0;
}