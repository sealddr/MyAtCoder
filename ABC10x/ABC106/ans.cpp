#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int N, K;
  cin >> N >> K;
  if(0 == (N % K)) {
    cout << 0 << endl;
    return 0;
  }
  cout << 1 << endl;
  return 0;
}