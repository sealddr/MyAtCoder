#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

const int MAXV = 100005;
int P[MAXV];
int Find(int A) {
  if(P[A] < 0) return A;
  return Find(P[A]);
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }

  reverse(all(a));
  reverse(all(b));
  rep(j, n) P[j] = -1;

  vector<ll> ans(m);
  ans[0] = (ll)n * (n - 1) / 2;
  rep(i, m - 1) {
    ans[i + 1] = ans[i];
    int pa = Find(a[i]), pb = Find(b[i]);
    if(pa != pb) {
      ans[i + 1] -= (ll)P[pa] * P[pb];
      if(P[pa] > P[pb]) swap(pa, pb);
      P[pa] += P[pb];
      P[pb] = pa;
    }
  }

  reverse(all(ans));
  rep(i, m) printf("%lld\n", ans[i]);
  return 0;
}
