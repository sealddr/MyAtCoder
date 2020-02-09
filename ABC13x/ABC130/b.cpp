#include <iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main() {
  int n, x;
  cin >> n >> x;
  int S = 0;
  rep(i, n) {
    int L;
    cin >> L;
    S += L;
    if(S > x) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << n + 1 << endl;
  return 0;
}