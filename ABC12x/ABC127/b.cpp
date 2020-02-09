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
  ll r, D, x;
  cin >> r >> D >> x;
  rep(i, 10) {
    x = r * x - D;
    cout << x << endl;
  }
  return 0;
}