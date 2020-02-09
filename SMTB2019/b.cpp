#include <algorithm>
#include <iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int MAXX = 54000;
int main() {
  int n;
  cin >> n;
  rep(i, MAXX + 1) {
    if(i * 108 / 100 == n) {
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
  return 0;
}