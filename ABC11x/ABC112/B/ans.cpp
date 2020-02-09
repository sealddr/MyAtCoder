#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int N, T;
  cin >> N >> T;

  int ans = 9999;
  for(int i = 0; i < N; i++) {
    int c, t;
    cin >> c >> t;
    if(t > T || ans < c) {
      continue;
    }
    ans = c;
  }
  if(9999 == ans) {
    cout << "TLE" << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
