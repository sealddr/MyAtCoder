#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int k, x;
  cin >> k >> x;
  for(int i = x - k + 1; i <= x + k - 1; i++) {
    cout << i << endl;
  }
  return 0;
}