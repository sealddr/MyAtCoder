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
  int ans = 0;
  char prev = '0';
  rep(i, n) {
    char c;
    cin >> c;
    if(c != prev)
      ans++;
    prev = c;
  }
  cout << ans << endl;
  return 0;
}