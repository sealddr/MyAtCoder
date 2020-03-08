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
const int INF = 1000000;
int main() {
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A), b(B);
  rep(i, A) cin >> a[i];
  rep(i, B) cin >> b[i];

  int ans = INF;
  vector<pair<P, int>> C(M);
  rep(j, M) {
    int x, y, c;
    cin >> x >> y >> c;
    x--, y--;
    ans = min(ans, a[x] + b[y] - c);
  }
  sort(all(a)), sort(all(b));
  ans = min(ans, a[0] + b[0]);
  cout << ans << endl;
  return 0;
}