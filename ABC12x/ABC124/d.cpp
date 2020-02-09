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
  string s;
  cin >> s;

  vector<int> cnts;
  int bt = 1;
  int cnt = 0;
  rep(i, n) {
    if(s[i] != (char)(bt + '0')) {
      cnts.push_back(cnt);
      bt ^= 1;
      cnt = 1;
    } else {
      ++cnt;
    }
  }
  if(cnt != 0) cnts.push_back(cnt);
  if(!bt) cnts.push_back(0);

  int m = (int)cnts.size();
  vector<int> acc(m + 1);
  acc[0] = 0;
  rep(i, m) acc[i + 1] = acc[i] + cnts[i];
  int d = 2 * k + 1;
  int ans = 0;
  for(int i = 0; i < m; i += 2) {
    int left = i;
    int right = min(i + d, m);
    ans = max(ans, acc[right] - acc[left]);
  }
  cout << ans << endl;

  return 0;
}
