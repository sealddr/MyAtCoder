#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll m = 1e9;
int main(void) {
  int n, k;
  ll s;
  cin >> n >> k >> s;
  rep(i, n) {
    ll a = s;
    if((i < n - k) && !(i % 2)) {
      a = (s + 1) / 2;
      if(s == 1 || s == 2)
        a = m;
    } else if((i < n - k) && (i % 2)) {
      a = s / 2 + 1;
      if(s == 1 || s == 2)
        a = m;
    }
    cout << a;
    if(i < n - 1)
      cout << ' ';
  }
  cout << endl;
  return 0;
}