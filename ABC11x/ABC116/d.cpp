#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int k, n;
  cin >> n >> k;
  vector<P> sushi(n);
  rep(i, n) {
    ll d;
    int t;
    cin >> t >> d;
    sushi[i] = make_pair(d, t);
  }
  sort(all(sushi));
  reverse(all(sushi));
  vector<bool> eaten(n);
  ll ans = 0;
  int prevt = sushi[0].second;
  int x = 1;
  int prevs = x * x + sushi[0].first;
  int cnt = 0;
  rep(i, n) {
    if(i == 0) continue;

    ll d = sushi[i].first;
    if(!eaten[sushi[i].second]
       && prevt != sushi[i].second) {
      d += 2 * x + 1;
    }
    if(d > prevs) {
      ans += d;
      
      if(!eaten[sushi[i].second]) {
        eaten[sushi[i].second] = true;
        x++;
        prevs += 2 * x + 1;
      }
    } else {
      ans += prevs;
      prevs = d;
      prevt = sushi[i].second;

      if(!eaten[prevt]) {
        eaten[sushi[prevt].second] = true;
        x++;
        prevs += 2 * x + 1;
      }
    }
    if(++cnt >= k) break;
  }
  cout << ans << endl;
  return 0;
}