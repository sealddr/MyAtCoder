#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int cnt = 0;
  rep(i, n - 1) if(s[i] != s[i + 1]) cnt++;
  int m = max(1, 1 + cnt - 2 * k);
  cout << n - m << endl;
  return 0;
}