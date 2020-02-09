#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> a(n + 1, 0);
  rep(rv, 2) {
    int cnt = 0;
    rep(i, n) {
      if(s[i] == '<') {
        cnt++;
        a[i + 1] = max(a[i + 1], cnt);
      } else {
        cnt = 0;
      }
    }
    reverse(s.begin(), s.end());
    rep(i, n) {
      if(s[i] == '<')
        s[i] = '>';
      else
        s[i] = '<';
    }
    reverse(a.begin(), a.end());
  }
  ll ans = 0;
  rep(i, n + 1) ans += a[i];
  cout << ans << endl;
  return 0;
}