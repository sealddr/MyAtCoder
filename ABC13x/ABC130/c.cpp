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
  int w, h, x, y;
  cin >> w >> h >> x >> y;
  double a = (double)w * (double)h / 2.0;
  int f = 0;
  if(w == 2 * x && h == 2 * y) f = 1;
  printf("%.20f %d\n", a, f);
  return 0;
}