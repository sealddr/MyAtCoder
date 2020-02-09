#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int n, L;
  cin >> n >> L;
  int minx = 101;
  rep(i, n) if(abs(minx) > abs(L + i)) minx = L + i;
  int ans = 0;
  rep(i, n) ans += (L + i);
  ans -= minx;
  cout << ans << endl;
  return 0;
}