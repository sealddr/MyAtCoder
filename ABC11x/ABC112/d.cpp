#include <algorithm>
#include <iostream>
using namespace std;
int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int n, m;
  cin >> n >> m;
  int ans = 1;
  for(int i = 1; i * i <= m; i++) {
    if(m % i == 0) {
      if(i <= m / n) ans = max(ans, i);
      if(i >= n) ans = max(ans, m / i);
    }
  }
  cout << ans << endl;
  return 0;
}