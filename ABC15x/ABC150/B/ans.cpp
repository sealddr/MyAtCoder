#include <iostream>
#include <string>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  for(int i = 0; i < n - 2; i++) {
    if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}