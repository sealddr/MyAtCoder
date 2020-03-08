#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  const int MAX_X = 1250;
  for(int x = 1; x <= MAX_X; x++) {
    if((8 * x) / 100 == a && (10 * x) / 100 == b) {
      cout << x << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}