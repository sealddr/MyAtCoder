#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

bool isACGT(char c) {
  string ACGT = "ACGT";
  rep(i, ACGT.size()) {
    if(c == ACGT[i]) return true;
  }
  return false;
}

int main() {
  string s;
  cin >> s;
  int ans = 0;
  int cnt = 0;
  rep(i, s.size()) {
    if(isACGT(s[i])) {
      cnt++;
      ans = max(ans, cnt);
    } else {
      cnt = 0;
    }
  }
  cout << ans << endl;
  return 0;
}