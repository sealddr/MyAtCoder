#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
const int INF = 1001;
int main() {
  int n, T;
  cin >> n >> T;
  vector<P> R(n);
  rep(i, n) {
    int c, t;
    cin >> c >> t;
    R[i] = make_pair(c, t);
  }
  sort(all(R));
  int ans = INF;
  rep(i, n) if(R[i].second <= T) ans = min(ans, R[i].first);
  if(ans == INF) {
    cout << "TLE" << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}