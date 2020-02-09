#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int Box[3];
  rep(i, 3) cin >> Box[i];
  int L[3];
  rep(i, 3) cin >> L[i];

  vector<int> P = {0, 1, 2};
  int ans = 0;
  do {
    int now = 1;
    rep(i, 3) now *= Box[i] / L[P[i]];
    ans = max(ans, now);
  } while(next_permutation(all(P)));
  cout << ans << endl;
  return 0;
}