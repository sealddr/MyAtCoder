#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n;
  cin >> n;
  int sumL = 0;
  int sumR = 0;
  vector<int> w(n);
  rep(i, n) {
    cin >> w[i];
    sumR += w[i];
  }
  int ans = sumR;
  rep(i, n) {
    sumL += w[i];
    sumR -= w[i];
    ans = min(ans, abs(sumR - sumL));
  }
  cout << ans << endl;
  return 0;
}