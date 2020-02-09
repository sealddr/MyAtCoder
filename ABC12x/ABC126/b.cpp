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
  int s;
  cin >> s;

  int u, l;
  u = s / 100;
  l = s % 100;

  bool yymm = false, mmyy = false;
  if(0 < l && l < 13) yymm = true;
  if(0 < u && u < 13) mmyy = true;

  string ans;
  if(yymm && mmyy)
    ans = "AMBIGUOUS";
  else if(yymm && !mmyy)
    ans = "YYMM";
  else if(!yymm && mmyy)
    ans = "MMYY";
  else
    ans = "NA";
  cout << ans << endl;
  return 0;
}