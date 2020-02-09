#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int N;
  cin >> N;
  if(1 == N) {
    cout << "Hello World" << endl;
    return 0;
  }
  if(2 == N) {
    int A, B;
    cin >> A >> B;
    cout << (A + B) << endl;
    return 0;
  }
  return 0;
}