#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void) {
  string str;
  cin >> str;
  int len = str.length();
  int count = 0;
  for(int s = 0, t = len - 1; s < len / 2; s++, t--) {
    if(str[s] != str[t]) {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}