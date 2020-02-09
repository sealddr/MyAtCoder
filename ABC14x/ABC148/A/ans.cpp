#include <iostream>
using namespace std;
int main(void) {
  int a, b;
  cin >> a >> b;
  int ans;
  if(a + b == 3) {
    ans = 3;
  } else if(a + b == 4) {
    ans = 2;
  } else if(a + b == 5) {
    ans = 1;
  }
  cout << ans << endl;
  return 0;
}