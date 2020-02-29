#include <iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main() {
  int n;
  cin >> n;
  int MAX_C = 100 / 4;
  int MAX_D = 100 / 7;
  rep(i, MAX_C + 1) {
    rep(j, MAX_D + 1) if(i * 4 + j * 7 == n) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}