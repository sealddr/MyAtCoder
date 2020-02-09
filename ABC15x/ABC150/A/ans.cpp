#include <iostream>
using namespace std;
int main(void) {
  int k, x;
  cin >> k >> x;
  if(500 * k >= x) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}