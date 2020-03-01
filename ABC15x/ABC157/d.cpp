#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

class UnionFind {
public:
  vector<int> parent;
  int root(int a) {
    if(parent[a] < 0) return a;
    return parent[a] = root(parent[a]);
  }
  UnionFind(int n) { parent = vector<int>(n, -1); }
  int size(int a) { return -parent[root(a)]; }
  int connect(int a, int b) {
    a = root(a);
    b = root(b);
    if(a == b) return false;
    if(size(a) < size(b)) swap(a, b);
    parent[a] += parent[b];
    parent[b] = a;
    return true;
  }
};

const int MAX_V = 100000;
vector<vector<int>> fto(MAX_V);
vector<vector<int>> bto(MAX_V);

int main() {
  int n;
  cin >> n;
  int m, k;
  cin >> m >> k;
  UnionFind uf(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    uf.connect(a, b);
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
  rep(i, n) {
    int ans = uf.size(i) - fto[i].size() - 1;
    for(auto x : bto[i]) {
      if(uf.root(i) == uf.root(x)) ans--;
    }
    cout << ans << ' ';
  }
  cout << endl;
  return 0;
}