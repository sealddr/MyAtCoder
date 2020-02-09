#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<bool>> isOpen(h + 2, vector<bool>(w + 2));
  rep(i, h) {
    int y = i + 1;
    string s;
    cin >> s;
    rep(j, w) {
      int x = j + 1;
      if('.' == s[j]) isOpen[y][x] = true;
    }
  }
  vector<vector<int>> nOpenL(h + 2, vector<int>(w + 2));
  vector<vector<int>> nOpenR(h + 2, vector<int>(w + 2));
  vector<vector<int>> nOpenU(h + 2, vector<int>(w + 2));
  vector<vector<int>> nOpenD(h + 2, vector<int>(w + 2));
  rep(i, h) rep(j, w) {
    int x = j + 1;
    int y = i + 1;
    if(isOpen[y][x])
      if(isOpen[y][x - 1])
        nOpenL[y][x] = nOpenL[y][x - 1] + 1;
  }
  rep(i, h) for(int j = w - 1; j >= 0; j--) {
    int x = j + 1;
    int y = i + 1;
    if(isOpen[y][x])
      if(isOpen[y][x + 1])
        nOpenR[y][x] = nOpenR[y][x + 1] + 1;
  }
  rep(i, h) rep(j, w) {
    int x = j + 1;
    int y = i + 1;
    if(isOpen[y][x])
      if(isOpen[y - 1][x])
        nOpenU[y][x] = nOpenU[y - 1][x] + 1;
  }
  for(int i = h - 1; i >= 0; i--) rep(j, w) {
      int x = j + 1;
      int y = i + 1;
      if(isOpen[y][x])
        if(isOpen[y + 1][x])
          nOpenD[y][x] = nOpenD[y + 1][x] + 1;
    }
  int ans = 0;
  rep(i, h) rep(j, w) {
    int x = j + 1;
    int y = i + 1;
    int now = nOpenL[y][x] + nOpenR[y][x] + nOpenU[y][x]
              + nOpenD[y][x] + 1;
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}