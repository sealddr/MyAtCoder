#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  ll H, W;
  cin >> H >> W;
  if(H == 1 || W == 1) {
    cout << 1 << endl;
    return 0;
  }
  ll ans = ((H + 1LL) / 2LL) * ((W + 1LL) / 2LL);
  ans += (H / 2LL) * (W / 2LL);
  cout << ans << endl;
  return 0;
}