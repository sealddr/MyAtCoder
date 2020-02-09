#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  string s;
  cin >> s;
  if(s[0] == s[1] || s[1] == s[2] || s[2] == s[3])
    cout << "Bad" << endl;
  else
    cout << "Good" << endl;
  return 0;
}