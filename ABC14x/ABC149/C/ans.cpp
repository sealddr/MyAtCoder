#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool is_prime(int n) {
  if(n % 2 == 0) {
    return false;
  }
  for(int i = 3; i * i <= n; i += 2) {
    if(n % i == 0) {
      return false;
    }
  }
  return true;
}

int main(void) {
  int x;
  cin >> x;
  int ans = x;
  if(ans == 2) {
    cout << ans << endl;
    return 0;
  }
  while(true) {
    if(is_prime(ans)) {
      cout << ans << endl;
      return 0;
    }
    ans++;
  }
  return 0;
}