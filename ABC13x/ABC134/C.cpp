#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int x;
  int max1 = 0;
  rep(i, n) {
    if(max1 < a[i]) {
      max1 = a[i];
      x = i;
    }
  }
  int max2 = 0;
  rep(i, n) {
    if(i == x) continue;
    max2 = max(max2, a[i]);
  }
  rep(i, n) {
    if(i == x)
      printf("%d\n", max2);
    else
      printf("%d\n", max1);
  }
  return 0;
}