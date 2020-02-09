#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  long long N, M;
  cin >> N >> M;
  long long ans = 0;
  for(long long p = 1; p <= sqrt(M); p++) {
    if(0 == M % p) {
      if(N * p <= M) {
        ans = max(ans, p);
      }
      if(N * (M / p) <= M) {
        ans = max(ans, M / p);
      }
    }
  }
  cout << ans << endl;
  return 0;
}