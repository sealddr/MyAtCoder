#include <cmath>
#include <iostream>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(void) {
  int a, b, x;
  cin >> a >> b >> x;
  double ans;
  if(2 * x - a * a * b > 0)
    ans = 180.0
          * atan((long double)(2 * (a * a * b - x))
                 / (long double)(a * a * a))
          / acos(-1);
  else
    ans = 180.0
          * atan((double)(a * b * b) / (double)(2 * x))
          / acos(-1);
  printf("%.10f\n", ans);
  return 0;
}