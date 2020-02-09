#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
int main() {
  int a, b, k;
  cin >> a >> b >> k;
  if(a < b) swap(a, b);
  int cnt = 0;
  for(int div = b; div >= 1; div--) {
    if(a % div == 0 && b % div == 0) {
      cnt++;
      if(cnt == k) {
        cout << div << endl;
        return 0;
      }
    }
  }
}