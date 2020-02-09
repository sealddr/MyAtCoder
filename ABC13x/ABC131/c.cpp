#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main(void) {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  auto f = [&](ll x) {
    return x - (x / c + x / d - x / (lcm(c, d)));
  };
  cout << f(b) - f(a - 1) << endl;
  return 0;
}