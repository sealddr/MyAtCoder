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
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> ans(n);
  rep(i, n) rep(j, i) {
    ++ans[min((i - j),
              (abs(j + 1 - x) + abs(i + 1 - y) + 1))];
  }
  rep(i, n) {
    if(i == 0) continue;
    cout << ans[i] << endl;
  }
  return 0;
}