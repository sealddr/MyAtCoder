#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
const int MAX_D = 10;

int sol[1024];
const int INF = 2000;

int main() {
  int d, g;
  cin >> d >> g;
  g /= 100;
  vector<int> p(d);
  vector<int> c(d);
  rep(i, d) cin >> p[i] >> c[i];
  rep(i, d) c[i] /= 100;

  rep(bm, 1 << d) {
    int di = 0;
    int nowscore = 0;
    vector<int> cnt(d);
    rep(di, d) if(bm >> di & 1) {
      cnt[di] = p[di];
      nowscore += (di + 1) * p[di];
      nowscore += c[di];
    }
    int nowsolved = 0;
    rep(di, d) nowsolved += cnt[di];
    sol[bm] = nowsolved;
    if(nowscore >= g) continue;
    for(int di = d - 1; di >= 0; di--) {
      if(bm >> di & 1) continue;
      cnt[di] = min(p[di], (g - nowscore + di) / (di + 1));
      nowscore += cnt[di] * (di + 1);
      sol[bm] += cnt[di];
      if(g < nowscore) break;
    }
  }
  int ans = INF;
  rep(bm, 1 << d) ans = min(ans, sol[bm]);
  cout << ans << endl;
  return 0;
}