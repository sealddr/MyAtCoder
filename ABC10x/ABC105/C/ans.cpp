#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  ll n;
  cin >> n;
  if(!n) {
    cout << 0 << endl;
    return 0;
  }
  string ans = "";
  while(n != 1) {
    if(n < 0 && n % 2) {
      n -= 2;
      n = (-n / 2);
      ans.push_back('1');
    } else if(n % 2) {
      n /= 2;
      n = -n;
      ans.push_back('1');
    } else {
      n /= 2;
      n = -n;
      ans.push_back('0');
    }
  }
  ans.push_back('1');
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}