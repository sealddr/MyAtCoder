#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)

const int MAXN = 100;
vector<int> X(MAXN), Y(MAXN);
vector<ll> H(MAXN);
int n;

bool f(ll h, int cx, int cy) {
  rep(i, n) {
    ll now = h - abs(X[i] - cx) - abs(Y[i] - cy);
    if(H[i] <= now) return true;
  }
  return false;
}

bool check(ll h, int cx, int cy) {
  rep(i, n) {
    ll now = h - abs(X[i] - cx) - abs(Y[i] - cy);
    if(H[i] != max(now, 0LL)) return false;
  }
  return true;
}

int main() {
  cin >> n;
  rep(i, n) cin >> X[i] >> Y[i] >> H[i];
  ll h;
  rep(i, 101) rep(j, 101) {
    ll ok = 10000000000;
    ll ng = 0;
    while(abs(ok - ng) > 1) {
      ll mid = (ok + ng) / 2;
      if(f(mid, i, j))
        ok = mid;
      else
        ng = mid;
    }
    h = ok;
    if(check(h, i, j)) {
      printf("%d %d %lld\n", i, j, h);
      return 0;
    }
  }
}