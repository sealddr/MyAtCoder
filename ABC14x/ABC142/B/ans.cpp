#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int N, K;
  cin >> N >> K;
  int ans = 0;
  int h;
  for(int i = 0; i < N; i++) {
    cin >> h;
    if(h >= K) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}