#include <algorithm>
#include <iostream>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(void) {
  int n;
  cin >> n;
  ll cnt[10][10];
  rep(i, 10) rep(j, 10) cnt[i][j] = 0;
  rep(i, n + 1) {
    if(i == 0) continue;
    int rd = i % 10;
    int ld = i;
    while(ld / 10) ld /= 10;
    ++cnt[rd][ld];
  }
  ll ans = 0;
  rep(i, 10) rep(j, 10) ans += cnt[i][j] * cnt[j][i];
  cout << ans << endl;
  return 0;
}