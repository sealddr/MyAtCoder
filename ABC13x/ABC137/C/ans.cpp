#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) {
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
  }
  sort(s.begin(), s.end());
  vector<int> vec(n);
  int cnt = 1;
  rep(i, n - 1) {
    bool eq = true;
    rep(j, 10) {
      if(s[i][j] != s[i + 1][j]) {
        eq = false;
        break;
      }
    }
    if(eq) {
      cnt++;
    } else {
      vec.push_back(cnt);
      cnt = 1;
    }
  }
  vec.push_back(cnt);
  ll ans = 0;
  for(ll k : vec) {
    ans += k * (k - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}