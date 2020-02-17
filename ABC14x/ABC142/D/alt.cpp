#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long a, long long b) {
  if(b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main(void) {
  long long a, b;
  cin >> a >> b;
  long long g = gcd(a, b);
  int ans = 1;
  int n = g;
  for(int i = 2; i * i < g; i++) {
    if(0 == n % i) {
      ans += 2;
      while(0 == (n % i)) {
        n = n / i;
      }
    }
    if(1 == n) {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
