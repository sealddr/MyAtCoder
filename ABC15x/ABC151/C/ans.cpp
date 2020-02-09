#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;
int main(void) {
  int n, m;
  cin >> n >> m;
  vector<int> p(m);
  vector<string> s(m);
  rep(i, m) cin >> p[i] >> s[i];
  rep(i, m) p[i]--;
  vector<bool> aced(n, false);
  vector<int> pns(n, 0);
  int acs = 0;
  rep(i, m) {
    if(aced[p[i]])
      continue;
    if(s[i] == "AC") {
      acs++;
      aced[p[i]] = true;
    } else {
      pns[p[i]]++;
    }
  }
  int ps = 0;
  rep(i, n) if(aced[i]) ps += pns[i];
  cout << acs << ' ' << ps << endl;
  return 0;
}