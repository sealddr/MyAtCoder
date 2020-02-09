#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
const ll mod = 1000000007;
int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> broken(n);
  rep(i, m) {
    int a;
    cin >> a;
    broken[a] = true;
  }
  vector<ll> a(n + 1);
  a[0] = 1;
  if(!broken[1]) a[1] = 1;
  rep(i, n - 1) {
    if(!broken[i + 2]) {
      if(!broken[i]) a[i + 2] = (a[i] + a[i + 2]) % mod;
      if(!broken[i + 1])
        a[i + 2] = (a[i + 1] + a[i + 2]) % mod;
    }
  }
  cout << a[n] << endl;
  return 0;
}