#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> vec(n);
  unordered_map<int, int> mp;
  rep(i, m) {
    int s, c;
    cin >> s >> c;
    if(mp.count(s)) {
      if(c != vec[s - 1]) {
        cout << -1 << endl;
        return 0;
      }
    }
    mp[s] = 1;
    vec[s - 1] = c;
  }
  if(n > 1) {
    if(mp.count(1) && vec[0] == 0) {
      cout << -1 << endl;
      return 0;
    }
    if(!mp.count(1)) vec[0] = 1;
  }
  rep(i, n) cout << vec[i];
  cout << endl;
  return 0;
}