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
  sort(all(h));
  int l = 0, r = k - 1;
  int ans = h[r] - h[l];
  while(r < n) {
    ans = min(ans, h[r] - h[l]);
    l++, r++;
  }
  cout << ans << endl;
  return 0;
}