#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
  int N, R;
  cin >> N >> R;
  cout << (N >= 10 ? R : R + 100 * (10 - N)) << endl;
  return 0;
}