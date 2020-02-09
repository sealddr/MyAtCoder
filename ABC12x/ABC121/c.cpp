#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n, m;
  cin >> n >> m;

  vector<P> hambai(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    hambai[i] = make_pair(a, b);
  }
  sort(all(hambai));
  ll ans = 0;
  rep(i, n) {
    if(m <= 0) break;
    ll kounyu = min(m, hambai[i].second);
    ans += hambai[i].first * kounyu;
    m -= kounyu;
  }
  cout << ans << endl;

  return 0;
}