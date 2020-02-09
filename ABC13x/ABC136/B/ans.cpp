#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int n;
  cin >> n;
  int ans = 0;
  ans += min(9, n);
  ans += min(900, max(n - 99, 0));
  ans += min(90000, max(n - 9999, 0));
  cout << ans << endl;
  return 0;
}