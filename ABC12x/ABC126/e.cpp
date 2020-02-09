#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

const int MAXV = 100005;
vector<vector<int>> to(MAXV);
vector<bool> chk(MAXV);

void dfs(int v, int p) {
  chk[v] = true;
  for(auto u : to[v]) {
    if(chk[u]) continue;
    dfs(u, v);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  to.resize(n);
  rep(i, m) {
    int x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    to[x].push_back(y);
    to[y].push_back(x);
  }
  chk.resize(n);
  int ans = 0;
  rep(i, n) {
    if(chk[i]) continue;
    dfs(i, -1);
    ans++;
  }
  cout << ans << endl;
  return 0;
}