#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;
int main(void) {
  int n, k, m;
  cin >> n >> k >> m;
  int a;
  int sum = 0;
  rep(i, n - 1) {
    cin >> a;
    sum += a;
  }
  if(sum + k < n * m) {
    cout << -1 << endl;
    return 0;
  }
  if(sum >= n * m) {
    cout << 0 << endl;
    return 0;
  }
  cout << n * m - sum << endl;
  return 0;
}