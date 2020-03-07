#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  string s;
  int nq;
  cin >> s >> nq;
  string l = "", r = "";
  bool flg = 0;
  rep(i, nq) {
    int t;
    cin >> t;
    if(t == 1) flg ^= 1;
    if(t == 2) {
      int f;
      char c;
      cin >> f >> c;

      if(flg ^ (f % 2))
        l = c + l;
      else
        r = r + c;
    }
  }
  s = l + s;
  s = s + r;
  if(flg) reverse(all(s));
  cout << s << endl;
  return 0;
}