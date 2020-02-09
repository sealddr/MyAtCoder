#include <iostream>
#include <string>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for(int i = 0; i < s.length(); i++) {
    char t = 'A' + (s[i] + n - 'A') % 26;
    cout << t;
  }
  cout << endl;
  return 0;
}