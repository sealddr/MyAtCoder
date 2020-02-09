#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll a, b, x;
const ll MAX = 1000000001;

ll d(ll n) {
  if(n < 10) return 1;
  return 1 + d(n / 10);
}

bool buy(ll n) { return (a * n + b * d(n) <= x); }

int main(void) {
  cin >> a >> b >> x;
  ll ok = 0;
  ll ng = MAX;
  while(abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if(buy(mid))
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
  return 0;
}