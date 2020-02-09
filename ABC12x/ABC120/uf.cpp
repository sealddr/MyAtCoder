#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, m) {
    int na, nb;
    cin >> na >> nb;
    a[i] = --na, b[i] = --nb;
  }
  vector<ll> ans(m);
  ans[m - 1] = (ll)n * (n - 1) / 2;

  UnionFind uf(n);

  for(int i = m - 1; i > 0; i--) {
    ans[i - 1] = ans[i];
    if(uf.root(a[i]) != uf.root(b[i])) {
      ans[i - 1] -= (ll)uf.size(a[i]) * uf.size(b[i]);
      uf.connect(a[i], b[i]);
    }
  }

  rep(i, m) cout << ans[i] << endl;
  return 0;
}
