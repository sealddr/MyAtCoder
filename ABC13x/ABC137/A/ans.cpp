#include <algorithm>
#include <iostream>
using namespace std;
int main(void) {
  int a, b;
  cin >> a >> b;
  cout << max(a + b, max(a - b, a * b)) << endl;
  return 0;
}