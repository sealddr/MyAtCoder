#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  int m = n - k + 1;
  double ans = 0.0;
  rep(i, k) ans += ((double)p[i] + 1) / 2;
  double now = ans;
  for(int i = 0; i + k < n; i++) {
    now += ((double)p[i + k] + 1) / 2;
    now -= ((double)p[i] + 1) / 2;
    ans = max(ans, now);
  }
  printf("%.10f\n", ans);
  return 0;
}