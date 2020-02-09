#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define dbg(x) cerr << #x << ": " << x << endl

int MAXN = 200005;
vector<ll> dp(
  MAXN);    // free time when Mr.Kizahashi finished i-th job
int main(void) {
  int n;
  cin >> n;
  vector<P> job(n);
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    job[i] = make_pair(b, a);
  }
  sort(job.begin(), job.end());
  dp[0] = job[0].first - job[0].second;
  if(dp[0] < 0) {
    cout << "No" << endl;
    return 0;
  }
  for(int i = 1; i < n; i++) {
    dp[i] = dp[i - 1] + (job[i].first - job[i - 1].first)
            - job[i].second;
    if(dp[i] < 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}