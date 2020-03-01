#include <iostream>
using namespace std;
int main() {
  int n, k, keta;
  cin >> n >> k;
  for(keta = 0; n > 0; keta++, n /= k) {
  }
  cout << keta << endl;
  return 0;
}