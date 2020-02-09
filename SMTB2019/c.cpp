#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

const int MAXX = 100005;
int main() {
  int x;
  cin >> x;
  vector<bool> dp(MAXX);
  dp[0] = true;
  vector<int> item = {100, 101, 102, 103, 104, 105};
  rep(i, MAXX) {
    rep(j, item.size()) {
      if(i - item[j] < 0) continue;
      if(dp[i - item[j]]) dp[i] = true;
    }
  }
  if(dp[x])
    cout << 1 << endl;
  else
    cout << 0 << endl;
  return 0;
}