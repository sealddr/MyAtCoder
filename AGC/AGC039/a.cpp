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
  string s;
  ll k;
  cin >> s >> k;
  vector<int> cnts;
  int cnt = 1;
  char c = s[0];
  int n = s.size();
  rep(i, n - 1) {
    if(c == s[i + 1]) {
      ++cnt;
    } else {
      c = s[i + 1];
      cnts.push_back(cnt);
      cnt = 1;
    }
  }
  cnts.push_back(cnt);

  int m = cnts.size();
  if(m == 1) {
    cout << k * cnts[0] / 2 << endl;
    return 0;
  }

  ll ans = 0;
  rep(i, m) { ans += k * (cnts[i] / 2); }
  if(s[0] == s[n - 1] && cnts[0] % 2 == 1
     && cnts[m - 1] % 2 == 1) {
    ans += k - 1;
  }
  cout << ans << endl;
  return 0;
}