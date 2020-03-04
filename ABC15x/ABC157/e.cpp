#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n, q;
  string s;
  cin >> n >> s >> q;
  vector<set<int>> idxs(26);
  rep(i, n) idxs[s[i] - 'a'].emplace(i);
  rep(qi, q) {
    int qcode;
    cin >> qcode;
    if(qcode == 1) {
      int i;
      char c;
      cin >> i >> c;
      i--;
      idxs[s[i] - 'a'].erase(i);
      s[i] = c;
      idxs[s[i] - 'a'].emplace(i);
    } else {
      int l, r;
      cin >> l >> r;
      int begin = l - 1, end = r;
      int cnt = 0;
      rep(ci, 26) {
        auto x = idxs[ci].lower_bound(begin);
        if(x != idxs[ci].end() && *x < end) cnt++;
      }
      cout << cnt << endl;
    }
  }
  return 0;
}