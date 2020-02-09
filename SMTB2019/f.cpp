#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  int t[2];
  cin >> t[0] >> t[1];
  ll a[2], b[2];
  cin >> a[0] >> a[1];
  cin >> b[0] >> b[1];

  if(a[0] < b[0]) {
    swap(a[0], b[0]);
    swap(a[1], b[1]);
  }

  ll c[2] = {a[0] - b[0], a[1] - b[1]};
  ll x[2] = {c[0] * t[0], c[1] * t[1]};
  if(0 < x[0] + x[1]) {
    cout << 0 << endl;
    return 0;
  }
  if(x[0] == -x[1]) {
    cout << "infinity" << endl;
    return 0;
  }

  ll dx = abs(x[1] + x[0]);
  ll ans = 1;
  ans += 2 * (x[0] / dx);
  if(x[0] % dx == 0) ans--;
  cout << ans << endl;
  return 0;
}