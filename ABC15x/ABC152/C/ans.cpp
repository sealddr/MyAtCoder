#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int INF = 200005;
int main(void) {
  int n;
  cin >> n;
  int p;
  int ans = 0;
  int prev = INF;
  rep(i, n) {
    cin >> p;
    if(p < prev) {
      ans++;
      prev = p;
    }
  }
  cout << ans << endl;
  return 0;
}