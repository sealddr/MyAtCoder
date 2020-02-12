#include <iostream>
#include <unordered_map>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main() {
  int n;
  cin >> n;
  n++;
  unordered_map<int, int> mp;
  rep(i, n) {
    int k = i;
    for(int j = 2; j <= k; j++) {
      while(k % j == 0) {
        mp[j]++;
        k = k / j;
      }
    }
  }

  int cnt = 0;
  rep(i, n) rep(j, i) rep(k, j) {
    if(mp[i] >= 2 && mp[j] >= 4 && mp[k] >= 4) cnt++;
    if(mp[i] >= 4 && mp[j] >= 2 && mp[k] >= 4) cnt++;
    if(mp[i] >= 4 && mp[j] >= 4 && mp[k] >= 2) cnt++;
  }
  rep(i, n) rep(j, i) {
    if(mp[i] >= 14 && mp[j] >= 4) cnt++;
    if(mp[i] >= 4 && mp[j] >= 14) cnt++;
    if(mp[i] >= 2 && mp[j] >= 24) cnt++;
    if(mp[i] >= 24 && mp[j] >= 2) cnt++;
  }
  rep(i, n) if(mp[i] >= 74) cnt++;

  cout << cnt << endl;
  return 0;
}