#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> b(n, 0);
  for(ll i = n; i > 0; i--) {
    int sum = 0;
    for(ll k = n / i * i; k > 0; k -= i) {
      if(i != k) {
        sum += b[k - 1];
      } else if(sum % 2 != a[k - 1]) {
        b[k - 1]++;
      }
    }
  }

  int m = 0;
  rep(i, n) if(b[i]) m++;
  printf("%d\n", m);
  rep(i, n) if(b[i]) printf("%d\n", i + 1);
}