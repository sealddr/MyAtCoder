#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (n); ++i)

const int MAXV = 200005;
vector<vector<int>> to(MAXV);
vector<ll> cnt(MAXV);
vector<ll> xsum(MAXV, 0);

void dfs(int v, int p, ll sum) {
  cnt[v] = sum;
  cnt[v] += xsum[v];
  for(int w : to[v]) {
    if(w == p) continue;
    dfs(w, v, cnt[v]);
  }
  return;
};

int main(void) {
  int n, q;
  cin >> n >> q;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vector<P> query(q);
  rep(i, q) {
    int p, x;
    cin >> p >> x;
    p--;
    query[i] = make_pair(p, x);
  }

  rep(i, q) xsum[query[i].first] += query[i].second;
  dfs(0, -1, 0);
  rep(i, n - 1) cout << cnt[i] << ' ';
  cout << cnt[n - 1] << endl;
  return 0;
}