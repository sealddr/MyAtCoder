#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> Graph;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

vector<int> color;
// if the graph has a cycle of odd length then return
// false.
bool dfs(const Graph& g, int v, int col) {
  color[v] = col;
  for(auto u : g[v]) {
    if(color[u] != -1) {
      if(color[u] == col) return false;
      continue;
    }
    if(!dfs(g, u, 1 ^ col)) return false;
  }
  return true;
}

vector<int> dist;
// bfs from the fixed s.
void bfs(const Graph& g, int s) {
  queue<int> que;
  dist[s] = 0;
  que.push(s);
  while(que.size()) {
    int v = que.front();
    que.pop();
    for(int u : g[v]) {
      if(dist[u] >= 0) continue;
      dist[u] = dist[v] + 1;
      que.push(u);
    }
  }
}

int main() {
  int n;
  cin >> n;
  Graph g(n);
  rep(i, n) {
    string s;
    cin >> s;
    rep(j, n) if(s[j] == '1') g[i].push_back(j);
  }

  color.assign(n, -1);
  if(!dfs(g, 0, 0)) {
    cout << -1 << endl;
    return 0;
  }

  int ans = 0;
  rep(i, n) {
    dist.assign(n, -1);
    bfs(g, i);
    rep(j, n) ans = max(ans, dist[j]);
  }

  ++ans;
  cout << ans << endl;
  return 0;
}