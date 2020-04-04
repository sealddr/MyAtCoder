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
  int k;
  cin >> k;
  int cnt = 0;
  ll n = 0;
  ll d = 1;
  while(cnt < k) {
    n += d;
    d = 1;
    ll m = n;
    bool ok = true;
    while(m / 10) {
      ll r = m % 10;
      ll l = (m / 10) % 10;
      if(abs(l - r) > 1) {
        ok = false;
        break;
      }

      m /= 10;
      d *= 10;
    }
    if(ok) {
      cnt++;
      d = 1;
    } else {
      d -= n % d;
    }
  }
  cout << n << endl;
  return 0;
}