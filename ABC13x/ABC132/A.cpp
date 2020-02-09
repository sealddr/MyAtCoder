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
  bool ok = false;
  if(s[0] == s[1] && s[2] == s[3] && s[0] != s[2]) {
    ok = true;
  } else if(s[0] == s[2] && s[1] == s[3] && s[0] != s[1]) {
    ok = true;
  } else if(s[0] == s[3] && s[1] == s[2] && s[0] != s[1]) {
    ok = true;
  }
  if(ok) {
    cout << "Yes" << endl;

  } else {
    cout << "No" << endl;
  }
  return 0;
}