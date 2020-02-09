#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int N;
  cin >> N;
  int Bi, Bip1;
  cin >> Bi;
  int ans = Bi;
  for(int i = 2; i < N; i++) {
    cin >> Bip1;
    ans += min(Bi, Bip1);
    Bi = Bip1;
  }
  ans += Bi;
  cout << ans << endl;
  return 0;
}