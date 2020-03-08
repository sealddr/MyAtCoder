#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll k = n / (a + b);
  ll nb = a * k;
  ll rest = n - (a + b) * k;
  nb += min(rest, a);
  cout << nb << endl;
  return 0;
}