#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int a;
  string s;
  cin >> a >> s;
  if(a >= 3200) {
    cout << s << endl;
    return 0;
  }
  cout << "red" << endl;
  return 0;
}