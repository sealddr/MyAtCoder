#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int N;
  cin >> N;
  vector<int> x(N);
  vector<int> y(N);
  vector<int> h(N);
  for(int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> h[i];
  }
  bool isSummit;
  int Cx = 0, Cy = 0;
  int H;

  for(int i = 0; i <= 100; i++) {
    for(int j = 0; j <= 100; j++) {
      H = -1;
      isSummit = true;
      for(int k = 0; k < N; k++) {
        if(h[k] == 0) {
          continue;
        }
        if(-1 == H) {
          H = abs(j - x[k]) + abs(i - y[k]) + h[k];
          continue;
        }
        if(H != abs(j - x[k]) + abs(i - y[k]) + h[k]) {
          isSummit = false;
          break;
        }
      }
      if(isSummit) {
        for(int k = 0; k < N; k++) {
          if(h[k] == 0
             && 0 < H - abs(j - x[k]) - abs(i - y[k])) {
            isSummit = false;
            break;
          }
        }
      }

      if(isSummit) {
        Cx = j;
        break;
      }
    }
    if(isSummit) {
      Cy = i;
      break;
    }
  }
  cout << Cx << ' ' << Cy << ' ' << H << endl;
  return 0;
}
