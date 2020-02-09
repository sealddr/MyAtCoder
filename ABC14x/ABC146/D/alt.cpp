#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int N_MAX = 100005;

int k = 0;
vector<int> c(N_MAX, 0);
vector<vector<int>> S(N_MAX);
// S[i] contains edegs connects to the i-th vertex.
vector<P> E(N_MAX);    // E[i] is the i-th edge.

void bfs() {
  queue<P> que;
  int v0 = 1;
  int d0 = S[v0].size();
  rep(i, d0) {
    int e0 = S[v0][i];
    c[e0] = i + 1;
    int v = E[e0].first;
    if(v0 == v) {
      v = E[e0].second;
    }
    que.push(make_pair(v, e0));
  }

  while(que.size()) {
    P p = que.front();
    que.pop();
    int v = p.first;
    int e = p.second;
    int d = S[v].size();
    int nc = 1;
    rep(i, d) {
      int ne = S[v][i];
      if(c[ne] > 0) continue;
      if(nc == c[e]) ++nc;
      c[ne] = nc++;
      int w = E[ne].first;
      if(v == w) w = E[ne].second;
      que.push(make_pair(w, ne));
    }
  }
}

int main(void) {
  int n;
  cin >> n;
  rep(i, n) {
    if(!i) continue;
    int a, b;
    cin >> a >> b;
    S[a].push_back(i);
    S[b].push_back(i);
    E[i] = make_pair(a, b);
  }
  rep(i, n + 1) {
    if(!i) continue;
    k = max(k, (int)S[i].size());
  }
  cout << k << endl;

  bfs();
  rep(i, n) {
    if(!i) continue;
    cout << c[i] << endl;
  }
  return 0;
}