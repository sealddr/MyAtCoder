#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
const int INF = 1000000000;
int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i, n) cin >> x[i];
  sort(all(x));
  int begin = x[0];
  int end = x[n - 1] + 1;
  int ans = INF;
  for(int p = begin; p < end; p++) {
    int sum = 0;
    rep(i, n) sum += (x[i] - p) * (x[i] - p);
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}