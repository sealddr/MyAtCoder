#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  if(b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main(void) {
  long long a, b;
  cin >> a >> b;
  ll g = gcd(a, b);
  int ans = 1;
  if(g % 2 == 0) {
    ans++;
    while(!(g % 2))
      g /= 2;
  }
  for(ll i = 3; i * i <= g; i += 2) {
    if(g % i == 0) {
      ans++;
      while(g % i == 0)
        g /= i;
    }
  }
  if(g != 1)
    ans++;
  cout << ans << endl;
  return 0;
}
