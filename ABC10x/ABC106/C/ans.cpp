#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  string ans = "";
  while(n != 0) {
    if(n % 2 != 0) {
      ans = "1" + ans;
      n--;
    } else {
      ans = "0" + ans;
    }
    n /= -2;
  }
  if(ans == "") {
    ans = "0";
  }
  cout << ans << endl;
  return 0;
}