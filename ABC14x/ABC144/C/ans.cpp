#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(void) {
  ll n;
  cin >> n;

  ll ans = n - 1;
  for(ll i = 2; i * i <= n; i++) {
    if(n % i != 0)
      continue;
    ans = min(ans, (i + n / i - 2));
  }
  cout << ans << endl;
  return 0;
}