#include <iostream>
using namespace std;
typedef long long ll;
int main(void) {
  ll a, b;
  cin >> a >> b;
  ll x = a + b;
  if(x % 2) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cout << (x >> 1) << endl;
  return 0;
}