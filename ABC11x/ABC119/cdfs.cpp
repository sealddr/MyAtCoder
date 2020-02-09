#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

const int INF = 100000;
int L[3];
vector<int> len(8);
int n;

int compute(vector<int> B) {
  int res = 0;
  int sl[3] = {0, 0, 0};
  int cnt[3] = {0, 0, 0};
  rep(i, n) {
    if(B[i] == 3) continue;
    sl[B[i]] += len[i];
    cnt[B[i]]++;
  }

  bool ok = true;
  rep(bamboo, 3) if(cnt[bamboo] == 0) ok = false;
  if(!ok) return INF;

  rep(bamboo, 3) {
    res += abs(L[bamboo] - sl[bamboo]);
    res += 10 * (cnt[bamboo] - 1);
  }
  return res;
}

ll dfs(int depth, vector<int> B) {
  if(depth == n) return compute(B);
  ll res = INF;
  rep(i, 4) {
    B[depth] = i;
    res = min(res, dfs(depth + 1, B));
  }
  return res;
}

int main() {
  cin >> n >> L[0] >> L[1] >> L[2];
  len.resize(n);
  rep(i, n) cin >> len[i];
  vector<int> B(n);
  int ans = dfs(0, B);
  cout << ans << endl;
  return 0;
}