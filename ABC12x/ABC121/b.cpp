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
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
  rep(j, m) cin >> b[j];
  int cnt = 0;
  rep(i, n) {
    int sum = 0;
    rep(j, m) {
      int a;
      cin >> a;
      sum += a * b[j];
    }
    sum += c;
    if(sum > 0) cnt++;
  }
  cout << cnt << endl;
  return 0;
}