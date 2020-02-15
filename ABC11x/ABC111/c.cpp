#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n;
  cin >> n;
  map<int, int> even_mp, odd_mp;
  bool flg = 0;
  rep(i, n) {
    int a;
    cin >> a;
    if(flg)
      even_mp[a]++;
    else
      odd_mp[a]++;
    flg ^= 1;
  }
  priority_queue<P> eq, oq;
  for(auto ex : even_mp) {
    eq.emplace(make_pair(ex.second, ex.first));
  }
  for(auto ox : odd_mp) {
    oq.emplace(make_pair(ox.second, ox.first));
  }
  P ep = eq.top();
  eq.pop();
  P op = oq.top();
  oq.pop();
  int ans = n - ep.first - op.first;
  if(ep.second == op.second) {
    if(eq.empty()) {
      if(oq.empty())
        ans = n / 2;
      else {
        P nop = oq.top();
        ans = n - ep.first - nop.first;
      }
    } else if(oq.empty()) {
      P nep = eq.top();
      ans = n - nep.first - op.first;
    } else {
      P nop = oq.top();
      P nep = eq.top();
      ans = min(n - ep.first - nop.first,
                n - nep.first - op.first);
    }
  }
  cout << ans << endl;
}