#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
const ll INF = 500005;
int main(void) {
  string s;
  cin >> s;
  int desc = 0;
  int n = s.size();
  int cptl = 0;
  ll ans = 0;
  int h = 0;
  rep(i, n) {
    if(s[i] == '>') {
      ++desc;
      if(h > 0) {
        h = 0;
        continue;
      }
      ans += desc - 1;
      if(desc > cptl) ans++;
    } else {
      ++h;
      ans += cptl = h;
      desc = 0;
    }
  }
  cout << ans << endl;
  return 0;
}