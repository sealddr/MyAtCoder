#include <iostream>
using namespace std;
int main() {
  int H, W;
  cin >> H >> W;
  int ch, cw;
  cin >> ch >> cw;
  cout << (H - ch) * (W - cw) << endl;
  return 0;
}