#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  int p[10];
  int q[10];
  for(int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> q[i];
  }
  int a = 0, b = 0;
  for(int i = n - 2, k = 1; i >= 0; i--, k *= n - i - 1) {
    for(int j = n - 1; j > i; j--) {
      if(p[i] > p[j]) {
        a += k;
      }
      if(q[i] > q[j]) {
        b += k;
      }
    }
  }
  cout << abs(a - b) << endl;
  return 0;
}