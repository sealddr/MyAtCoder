#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

const int MAXV = 100005;
const int BLACK = 1;    // odd
const int WHITE = 0;    // even

vector<vector<P>> to(MAXV);
vector<int> col(MAXV);
void dfs(int v, int p, int len) {
  col[v] = p < 0 ? WHITE : (col[p] + len) % 2;
  for(auto u : to[v]) {
    if(u.first == p) continue;
    dfs(u.first, v, u.second);
  }
}

int main() {
  int n;
  cin >> n;

  col.resize(n);
  rep(i, n) col[i] = -1;

  rep(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    to[u].push_back(make_pair(v, w));
    to[v].push_back(make_pair(u, w));
  }
  dfs(0, -1, 0);
  rep(i, n) printf("%d\n", col[i]);
  return 0;
}