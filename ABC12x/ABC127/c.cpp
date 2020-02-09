#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n, m;
  cin >> n >> m;
  int L = 0, R = n + 1;
  rep(i, m) {
    int Li, Ri;
    cin >> Li >> Ri;
    L = max(L, Li);
    R = min(R, Ri);
  }
  cout << max(0, (R - L + 1)) << endl;
  return 0;
}