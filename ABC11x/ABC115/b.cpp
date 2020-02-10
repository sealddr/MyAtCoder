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
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  sort(all(p));
  reverse(all(p));
  int ans = p[0] / 2;
  for(int i = 1; i < n; i++) ans += p[i];
  cout << ans << endl;
  return 0;
}