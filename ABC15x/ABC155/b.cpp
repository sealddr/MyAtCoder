#include <iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main() {
  int n;
  cin >> n;
  rep(i, n) {
    int a;
    cin >> a;
    if(a % 2 == 1 || a % 3 == 0 || a % 5 == 0)
      continue;
    else {
      cout << "DENIED" << endl;
      return 0;
    }
  }
  cout << "APPROVED" << endl;
  return 0;
}