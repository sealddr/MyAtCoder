#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int h, w, n;
  cin >> h >> w >> n;
  int k = max(h, w);
  cout << (n + k - 1) / k << endl;
  return 0;
}