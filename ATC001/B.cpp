#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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
    int n, q;
    cin >> n >> q;
    UnionFind uf = UnionFind(n);
    rep(i, q){
        int p, a, b;
        cin >> p >> a >> b;
        if(p == 0) uf.connect(a, b);
        else printf("%s\n", uf.root(a) == uf.root(b) ? "Yes" : "No");
    }
    return 0;
}