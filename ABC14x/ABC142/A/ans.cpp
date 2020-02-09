#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  int m = (n + 1) / 2;
  double ans = (double)m / (double)n;
  cout << ans << endl;
  return 0;
}