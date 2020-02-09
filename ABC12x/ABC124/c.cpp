#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

int toi(char b) {
  switch(b) {
    case '0': return 0;
    case '1': return 1;
    default: return -1;
  }
}

int f(string s, char lc) {
  int res = 0;
  rep(i, s.size()) {
    res += toi(s[i]) ^ toi(lc);
    lc ^= 1;
  }
  return res;
}

int main() {
  string s;
  cin >> s;
  cout << min(f(s, '0'), f(s, '1')) << endl;
  return 0;
}