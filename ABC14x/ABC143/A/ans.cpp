#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(void) {
  int a, b;
  cin >> a >> b;
  cout << max(0, a - (b << 1)) << endl;
  return 0;
}