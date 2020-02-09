#include <algorithm>
#include <iostream>
#include <map>
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
  multimap<P, int> mp;
  rep(j, m) {
    ll b, c;
    cin >> b >> c;
    P p = make_pair(c, b);
    mp.insert(multimap<P, int>::value_type(p, j));
  }
  vector<P> vec(m);
  ll updating = n;
  for(auto x = mp.rbegin(); x != mp.rend(); ++x) {
    ll nb = min(updating, x->first.second);
    ll c = x->first.first;
    vec[x->second] = make_pair(nb, c);
    updating = max(0LL, updating - nb);
  }
  priority_queue<ll, vector<ll>, greater<ll>> queue;
  rep(i, n) queue.emplace(a[i]);
  rep(j, m) {
    for(int i = 0; i < vec[j].first; i++) {
      ll y = queue.top();
      queue.pop();
      queue.emplace(max(y, vec[j].second));
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