#include <iostream>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int keta = 0;
  while(n) {
    keta++;
    n /= k;
  }
  cout << keta << endl;
  return 0;
}