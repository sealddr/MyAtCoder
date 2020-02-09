#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  vector<bool> ansvec(101, false);
  for(int i = 0; i * 4 <= 100; i++) {
    for(int j = 0; j * 7 <= 100; j++) {
      if(4 * i + 7 * j > 100) {
        continue;
      }
      ansvec[4 * i + 7 * j] = true;
    }
  }
  int N;
  cin >> N;
  if(ansvec[N]) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}