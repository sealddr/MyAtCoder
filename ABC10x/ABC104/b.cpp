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
  cin >> s;
  int n = s.size();
  bool ok = true;
  if(s[0] != 'A') ok = false;
  int cntCapital = 0;
  int cntC = 0;
  rep(i, n) {
    if(1 < i && i < n - 1 && s[i] == 'C') cntC++;
    int nc = s[i] - 'a';
    dbg(s[i]);
    dbg(nc);
    if(nc < 0) cntCapital++;
  }
  if(cntCapital > 2) ok = false;
  if(cntC != 1) ok = false;
  if(ok)
    cout << "AC" << endl;
  else
    cout << "WA" << endl;
  return 0;
}