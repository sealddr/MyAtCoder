#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

ll f(ll x) {
  ll res = 0;
  res = ((x + 1) / 2) % 2;
  if(x % 2 == 0) res ^= x;
  return res;
}

ll f2(ll x) {
  if(x < 0) return 0;
  ll res = 0;
  int keta = 0;
  while(x >> keta) {
    ll loop = (1LL << (keta + 1));
    ll cnt = ((x + 1) / loop) * (loop / 2);
    cnt += max(0LL, ((x + 1) % loop) - (loop / 2));
    if(cnt % 2 == 1) res += (1LL << keta);
    keta++;
  }
  return res;
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << (f2(b) ^ f2(a - 1)) << endl;
  //  cout << (f(b) ^ f(a - 1)) << endl;
  return 0;
}