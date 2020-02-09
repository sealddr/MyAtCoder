#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, int> dists_from(int v, vector<int>* N);
map<int, int> dfs(int v, int d, int p, vector<int>* N);
int main(void) {
  int n, u, v;
  cin >> n >> u >> v;
  u--;
  v--;
  vector<int> N[n];
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    N[a].push_back(b);
    N[b].push_back(a);
  }
  map<int, int> dist_u = dists_from(u, N);
  map<int, int> dist_v = dists_from(v, N);
  int d = 0;
  for(int i = 0; i < n; i++) {
    if(dist_u[i] < dist_v[i]) {
      d = max(d, dist_v[i]);
    }
  }
  cout << d - 1 << endl;
  return 0;
}

map<int, int> dists_from(int v, vector<int>* N) {
  return dfs(v, 0, -1, N);
}

map<int, int> dfs(int v, int d, int p, vector<int>* N) {
  map<int, int> result{};
  for(const auto& u : N[v]) {
    if(u == p) {
      continue;
    }
    map<int, int> dists = dfs(u, d + 1, v, N);
    for(auto itr = dists.begin(); itr != dists.end();
        itr++) {
      result[itr->first] = itr->second;
    }
  }
  result[v] = d;
  return result;
}