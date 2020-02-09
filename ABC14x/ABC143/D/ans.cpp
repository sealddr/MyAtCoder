#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(void) {
  int n;
  cin >> n;
  vector<int> L(n);
  rep(i, n) cin >> L[i];
  sort(L.begin(), L.end());
  int ans = 0;
  rep(i, n) rep(j, i) {
    int ng = -1;
    int ok = j;
    while(abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      if(L[mid] + L[j] > L[i])
        ok = mid;
      else
        ng = mid;
    }
    ans += j - ok;
  }
  cout << ans << endl;
  return 0;
}