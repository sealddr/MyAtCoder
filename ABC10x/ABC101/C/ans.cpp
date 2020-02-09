#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll ok = 100000;
  ll ng = 0;
  while(abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if((mid - 1) * (k - 1) + k >= n)
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
  return 0;
}