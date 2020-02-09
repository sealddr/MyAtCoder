#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<P> op(m);
  rep(j, m) {
    ll b, c;
    cin >> b >> c;
    op[j] = make_pair(c, b);
  }
  sort(all(op));
  reverse(all(op));
  ll updating = n;
  rep(j, m) {
    ll nb = min(updating, op[j].second);
    op[j].second = nb;
    updating = max(0LL, updating - nb);
  }

  priority_queue<ll, vector<ll>, greater<ll>> queue;
  rep(i, n) queue.emplace(a[i]);
  rep(j, m) {
    for(int k = 0; k < op[j].second; k++) {
      ll na = queue.top();
      queue.pop();
      queue.emplace(max(na, op[j].first));
    }
  }

  ll ans = 0;
  while(queue.size()) {
    ans += queue.top();
    queue.pop();
  }
  cout << ans << endl;
  return 0;
}