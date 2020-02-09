#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int A, B;
  cin >> A >> B;
  int ans;
  if(A < B) {
    ans = 0;
  } else {
    ans = 1;
  }
  cout << ans << endl;
  return 0;
}