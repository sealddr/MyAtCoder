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
  string s;
  cin >> n >> s;
  int ans = 0;
  rep(i, 1000) {
    char c[3];
    c[0] = '0' + (i / 100);
    c[1] = '0' + (i % 100) / 10;
    c[2] = '0' + (i % 10);
    int keta = 0;
    rep(j, s.size()) {
      if(s[j] == c[keta]) {
        if(keta == 2) {
          ans++;
          break;
        } else {
          keta++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}