#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n;
  cin >> n;
  map<string, int> mp;
  int cnt = 0;
  rep(i, n) {
    string s;
    cin >> s;
    mp[s]++;
    cnt = max(cnt, mp[s]);
  }
  for(auto x : mp)
    if(x.second == cnt) cout << x.first << endl;
  return 0;
}