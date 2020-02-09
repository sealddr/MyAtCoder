#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> dists_from(int v);
void dfs(int v, int d, int p);

int n;
vector<int> N[200000];

vector<int> dists;

int main(void) {
  int u, v;
  cin >> n >> u >> v;
  u--;
  v--;
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    N[a].push_back(b);
    N[b].push_back(a);
  }
  vector<int> dist_u = dists_from(u);
  vector<int> dist_v = dists_from(v);
  int d = 0;
  for(int i = 0; i < n; i++) {
    if(dist_u[i] < dist_v[i]) {
      d = max(d, dist_v[i]);
    }
  }
  cout << d - 1 << endl;
  return 0;
}

vector<int> dists_from(int v) {
  dists = vector<int>(n);
  dfs(v, 0, -1);
  return dists;
}

void dfs(int v, int d, int p) {
  for(const auto& u : N[v]) {
    if(u == p) {
      continue;
    }
    dfs(u, d + 1, v);
  }
  dists[v] = d;
}