#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int n, k;
  cin >> n >> k;
  cout << ((n - 1) + (k - 1) - 1) / (k - 1) << endl;
  return 0;
}