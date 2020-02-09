#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  ll n;
  cin >> n;
  cout << (n - 1) * n / 2 << endl;
  return 0;
}