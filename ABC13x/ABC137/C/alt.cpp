#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
typedef unordered_map<string, int> Map;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) {
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
  }
  Map map;
  ll ans = 0;
  rep(i, n) {
    if(map.count(s[i]) == 0) {
      map[s[i]] = 1;
    } else {
      ans += map[s[i]];
      map[s[i]]++;
    }
  }
  cout << ans << endl;
  return 0;
}