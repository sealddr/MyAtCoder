#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void) {
  string s;
  string ans;
  cin >> s;
  if('S' == s[0]) {
    ans = "Cloudy";

  } else if('C' == s[0]) {
    ans = "Rainy";
  } else {
    ans = "Sunny";
  }
  cout << ans;
  return 0;
}