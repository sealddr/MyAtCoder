#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
const int INF = 10000;
int main() {
  vector<int> food(5);
  rep(i, 5) cin >> food[i];
  vector<int> idx = {0, 1, 2, 3, 4};
  int ans = INF;
  do {
    int et = 0;
    rep(i, 5) {
      et = 10 * ((et + 9) / 10);
      et += food[idx[i]];
    }
    ans = min(ans, et);
  } while(next_permutation(all(idx)));
  cout << ans << endl;
  return 0;
}