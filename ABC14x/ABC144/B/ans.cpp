#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(void) {
  int n;
  cin >> n;
  bool ok = false;
  for(int i = 1; i * i <= n; i++) {
    if(0 == n % i && (n / i) < 10) {
      ok = true;
      break;
    }
  }
  if(ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}