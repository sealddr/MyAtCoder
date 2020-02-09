#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> num_like(m);
  rep(i, n) {
    int k;
    cin >> k;
    rep(j, k) {
      int a;
      cin >> a;
      a--;
      num_like[a]++;
    }
  }
  int ans = 0;
  rep(i, m) if(n == num_like[i]) ans++;
  cout << ans << endl;
  return 0;
}