#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n;
  cin >> n;
  vector<int> H(n);
  rep(i, n) cin >> H[i];
  int cnt = 0;
  for(int h = 100; h > 0; h--) {
    bool eq = false;
    rep(i, n) {
      if(!eq && H[i] == h)
        eq = true, cnt++, H[i]--;
      else if(eq && H[i] == h)
        H[i]--;
      else if(!eq && H[i] < h)
        continue;
      else
        eq = false;
    }
  }
  cout << cnt << endl;
  return 0;
}