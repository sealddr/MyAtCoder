#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int n, a, b;
  cin >> n >> a >> b;
  cout << min(a * n, b) << endl;
  return 0;
}