#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

bool matchesACGT(char c) {
  bool res = false;
  char acgt[] = {'A', 'C', 'G', 'T'};
  rep(i, 4) if(c == acgt[i]) res = true;
  return res;
}

bool isACGT(string s, int pos, int len) {
  bool res = true;
  string subs = s.substr(pos, len);
  rep(i, len) {
    if(!matchesACGT(subs[i])) {
      res = false;
      break;
    }
  }
  return res;
}

int main() {
  string s;
  cin >> s;
  int ans = 0;
  for(int len = 0; len <= s.size(); len++)
    for(int pos = 0; pos <= s.size() - len; pos++)
      if(isACGT(s, pos, len)) ans = max(ans, len);
  cout << ans << endl;
  return 0;
}