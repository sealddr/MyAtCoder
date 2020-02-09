#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int N;
  cin >> N;
  int ans = 0;
  for(int n = 1; n <= N; n += 2) {
    int cnt = 0;
    for(int p = 1; p * p <= n; p++) {
      if(0 == n % p) {
        if(p * p == n) {
          cnt++;
        } else {
          cnt += 2;
        }
      }
    }
    if(8 == cnt) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}