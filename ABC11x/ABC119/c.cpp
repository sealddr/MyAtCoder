#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

int pow(int b, int e) {
  if(e == 0) return 1;
  if(e % 2 == 1) return pow(b, e - 1) * b;
  int m = pow(b, e >> 1);
  return m * m;
}

const int A = 0, B = 1, C = 2, NO = 3;
const int INF = 100000;

int main() {
  int n;
  int L[3];
  cin >> n >> L[0] >> L[1] >> L[2];
  vector<int> len(n);
  rep(i, n) cin >> len[i];
  vector<int> into(n);

  int ans = INF;
  rep(cand, pow(4, n)) {
    rep(i, n) into[i] = (cand / pow(4, i)) % 4;
    int sl[3] = {0, 0, 0};
    int cnt[3] = {0, 0, 0};
    rep(i, n) {
      if(into[i] == NO) continue;
      sl[into[i]] += len[i];
      cnt[into[i]]++;
    }

    bool ok = true;
    rep(bamboo, 3) if(cnt[bamboo] == 0) ok = false;
    if(!ok) continue;

    int now = 0;
    rep(bamboo, 3) {
      now += abs(L[bamboo] - sl[bamboo]);
      now += 10 * (cnt[bamboo] - 1);
    }
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}