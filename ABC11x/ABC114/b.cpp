#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
const int INF = 1000;
int main() {
  string s;
  cin >> s;
  int ans = INF;
  rep(i, s.size() - 2) {
    int x = (s[i + 2] - '0');
    x += 10 * (s[i + 1] - '0');
    x += 100 * (s[i] - '0');
    ans = min(ans, abs(753 - x));
  }
  cout << ans << endl;
  return 0;
}