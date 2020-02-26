#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
string trim(string s) {
  if(s == "0") return s;
  string t = "";
  int i = 0;
  while(s[i] == '0') i++;
  while(i < s.size()) {
    t = t + s[i];
    i++;
  }
  return t;
}
int main() {
  int n;
  cin >> n;
  if(n == 0) {
    cout << '0' << endl;
    return 0;
  }
  string s = "";
  while(n != 0) {
    int r = n % (-2);
    dbg(r);
    if(r == 0) s = "0" + s, n /= (-2);
    if(r == 1) s = "1" + s, n /= (-2);
    if(r == -1) s = "1" + s, n--, n /= (-2);
  }
  s = trim(s);
  cout << s << endl;
  return 0;
}