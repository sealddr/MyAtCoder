#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int A, B;
  cin >> A >> B;
  if((A * B) % 2 == 0) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}