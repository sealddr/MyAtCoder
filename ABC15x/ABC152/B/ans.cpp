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
  if(a > b) swap(a, b);
  int k = 1;
  int ans = 0;
  rep(i, b) {
    ans += a * k;
    k *= 10;
  }
  cout << ans << endl;
  return 0;
}