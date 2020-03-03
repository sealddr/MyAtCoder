#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

const int MAX_V = 100000;
vector<vector<int>> fto(MAX_V);
vector<vector<int>> bto(MAX_V);
vector<int> col(MAX_V);
// mp[i] stores the number of vertices with i-th color.
unordered_map<int, int> mp;

void dfs(int v, int p, int c) {
  col[v] = c;
  mp[c]++;
  for(auto w : fto[v]) {
    if(col[w] >= 0) continue;
    dfs(w, v, c);
  }
  return;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  fto.resize(n);
  bto.resize(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    fto[a].push_back(b);
    fto[b].push_back(a);
  }
  rep(i, k) {
    int c, d;
    cin >> c >> d;
    c--, d--;
    bto[c].push_back(d);
    bto[d].push_back(c);
  }
  col.resize(n);
  col.assign(n, -1);

  int ncol = 0;
  rep(i, n) {
    dbg(i);
    if(col[i] < 0) {
      dfs(i, -1, ncol);
      ncol++;
    }
  }
  rep(i, n) {
    int ans = mp[col[i]] - fto[i].size() - 1;
    for(auto j : bto[i])
      if(col[i] == col[j]) ans--;
    cout << ans;
    if(i != n - 1) cout << ' ';
  }
  cout << endl;
  return 0;
}