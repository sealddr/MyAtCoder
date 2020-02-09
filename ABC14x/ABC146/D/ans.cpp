#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N_MAX = 100005;
vector<int> c(N_MAX, 0);

vector<vector<int>> E(N_MAX);
vector<P> g(N_MAX);

int k;

void bfs() {
  queue<P> que;
  int v0 = 1;
  int d0 = E[v0].size();
  k = d0;
  rep(i, d0) {
    int e0i = E[v0][i];
    c[e0i] = i + 1;
    int vi = g[e0i].first;
    if(v0 == vi) {
      vi = g[e0i].second;
    }
    que.push(make_pair(vi, e0i));
  }
  while(que.size()) {
    P p = que.front();
    que.pop();
    int v = p.first;
    int e = p.second;
    int d = E[v].size();
    k = max(k, d);
    int nc = 0;
    rep(i, d) {
      int evi = E[v][i];
      if(c[evi] > 0)
        continue;
      if(++nc == c[e])
        ++nc;
      c[evi] = nc;
      int vi = g[evi].first;
      if(v == vi) {
        vi = g[evi].second;
      }
      que.push(make_pair(vi, evi));
    }
  }
}

int main(void) {
  int n;
  cin >> n;
  rep(i, n) {
    if(!i)
      continue;
    int a, b;
    cin >> a >> b;
    E[a].push_back(i);
    E[b].push_back(i);
    g[i] = make_pair(a, b);
  }
  bfs();
  cout << k << endl;
  rep(i, n) {
    if(!i)
      continue;
    cout << c[i] << endl;
  }
  return 0;
}