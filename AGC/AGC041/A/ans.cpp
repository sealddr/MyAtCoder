#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans;
  if((b - a) % 2) {
    ans = min(n - b, a - 1) + 1 + (b - a - 1) / 2;
  } else {
    ans = (b - a) / 2;
  }
  cout << ans << endl;
  return 0;
}