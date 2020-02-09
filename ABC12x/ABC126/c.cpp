#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)

// return the minimum number of t s.t., d*(2**t)>=x
int f(int d, int x) {
  int t = 0;
  while((ll)d * (1LL << t) < (ll)x) t++;
  return t;
}

int main() {
  int n, k;
  cin >> n >> k;
  double ans = 0.0;
  rep(i, n) {
    int dice = i + 1;
    ans += (1.0) / (double)(1LL << f(dice, k));
  }
  ans /= (double)n;
  printf("%.20f\n", ans);
  return 0;
}