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
  vector<int> cntR(n, 0);
  vector<int> cntL(n, 0);
  rep(i, n) {
    if(i == 0)
      cntR[0] = 1;
    else if(s[i] == 'R')
      cntR[i] = cntR[i - 1] + 1;
  }
  rep(i, n) {
    int j = n - 1 - i;
    if(j == n - 1)
      cntL[n - 1] = 1;
    else if(s[j] == 'L')
      cntL[j] = cntL[j + 1] + 1;
  }

  rep(i, n) {
    int ans = 0;
    if(i < n - 1)
      if(0 < cntR[i] && 0 < cntL[i + 1])
        ans += (cntR[i] + 1) / 2 + cntL[i + 1] / 2;
    if(0 < i)
      if(0 < cntL[i] && 0 < cntR[i - 1])
        ans += (cntL[i] + 1) / 2 + cntR[i - 1] / 2;
    printf("%d\n", ans);
  }
  return 0;
}