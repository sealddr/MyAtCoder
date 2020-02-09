#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void) {
  string s;
  cin >> s;
  for(int i = 0; i < s.length(); i++) {
    if(0 == i % 2 && 'L' == s[i]) {
      cout << "No" << endl;
      return 0;
    }
    if(1 == i % 2 && 'R' == s[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}