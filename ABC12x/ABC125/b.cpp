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
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  vector<int> c(n);
  rep(i, n) cin >> c[i];
  int ans = 0;
  rep(i, n) if(v[i] > c[i]) ans += (v[i] - c[i]);
  cout << ans << endl;
  return 0;
}