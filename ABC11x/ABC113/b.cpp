#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n;
  cin >> n;
  double t, a;
  cin >> t >> a;
  vector<double> H(n);
  rep(i, n) cin >> H[i];
  int idx = 0;
  auto d = [&](int i) {
    return fabs(t - H[i] * 0.006 - a);
  };
  double mind = d(0);
  rep(i, n) {
    if(mind > d(i)) {
      mind = d(i);
      idx = i;
    }
  }
  cout << ++idx << endl;
  return 0;
}