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
  int D;
  cin >> D;
  string ans;
  if(D == 25)
    ans = "Christmas";
  else if(D == 24)
    ans = "Christmas Eve";
  else if(D == 23)
    ans = "Christmas Eve Eve";
  else
    ans = "Christmas Eve Eve Eve";
  cout << ans << endl;
  return 0;
}