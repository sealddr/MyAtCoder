#include <iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int n, d;
  cin >> n >> d;
  cout << (n + (2 * d + 1) - 1) / (2 * d + 1) << endl;
  return 0;
}