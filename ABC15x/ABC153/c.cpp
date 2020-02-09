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
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  if(k > n) {
    cout << 0 << endl;
    return 0;
  }
  sort(all(h));
  reverse(all(h));
  rep(i, k) h[i] = 0;
  ll ans = 0;
  rep(i, n) ans += h[i];
  cout << ans << endl;

  return 0;
}