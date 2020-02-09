#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;
int main(void) {
  int n;
  string s;
  cin >> n >> s;
  if(n % 2 == 1) {
    cout << "No" << endl;
    return 0;
  }
  n >>= 1;
  string t0 = s.substr(0, n), t1 = s.substr(n, n);
  if(t0 == t1) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}