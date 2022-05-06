#include <vector>
using namespace std;

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