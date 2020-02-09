#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)

const ll INF = 1000000005;
int main(void) {
  int n;
  cin >> n;
  vector<ll> h(n + 1);
  rep(i, n) cin >> h[i];
  h[n] = INF;
  int ans = 0;
  int cnt = 0;
  rep(i, n) {
    if(h[i] < h[i + 1]) {
      cnt = 0;
    } else {
      ++cnt;
      ans = max(ans, cnt);
    }
  }
  cout << ans << endl;
  return 0;
}