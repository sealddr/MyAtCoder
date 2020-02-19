#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

const ll INF = (ll)(1e18) + 1;
const int MAXN = 200005;

vector<ll> a(MAXN);

bool f(ll x, ll k) {
  ll sum = 0LL;
  int n = a.size();
  rep(i, n) {
    bool sflg = a[i] < 0;
    int ng = sflg ? -1 : n;
    int ok = sflg ? n : -1;
    while(abs(ok - ng) > 1) {
      int mid = (ng + ok) / 2;
      if(a[mid] * a[i] < x)
        ok = mid;
      else
        ng = mid;
    }
    sum += sflg ? n - ok : ok + 1;
  }
  rep(i, n) if(a[i] * a[i] < x) sum--;
  sum >>= 1;
  return sum < k;
}

int main() {
  int n;
  ll k;
  cin >> n >> k;
  a.resize(n);
  rep(i, n) cin >> a[i];
  sort(all(a));
  ll ok = -INF, ng = INF;
  while(abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if(f(mid, k))
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
  return 0;
}