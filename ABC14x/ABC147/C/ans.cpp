#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int count(unsigned int n);

int main(void) {
  int n;
  cin >> n;
  n++;
  int A[n];
  int x[n][n];
  int y[n][n];
  for(int i = 1; i < n; i++) {
    cin >> A[i];
    for(int j = 1; j < A[i] + 1; j++) {
      cin >> x[i][j] >> y[i][j];
    }
  }

  int ans = 0;
  for(unsigned int temp_bitmap = 1;
      temp_bitmap < 1 << (n - 1); temp_bitmap++) {
    int cnt = count(temp_bitmap);
    if(cnt <= ans) {
      continue;
    }
    int mask = 1;
    bool contradict = false;
    for(int j = 1; j < n; j++, mask <<= 1) {
      if((temp_bitmap & mask) > 0) {
        for(int k = 1; k < A[j] + 1; k++) {
          int xjk = temp_bitmap & (1 << (x[j][k] - 1));
          if(xjk == 0 && y[j][k] == 1) {
            contradict = true;
          } else if(xjk > 0 && y[j][k] == 0) {
            contradict = true;
          }
          if(contradict) {
            break;
          }
        }
      }
      if(contradict) {
        break;
      }
    }
    if(contradict) {
      continue;
    }
    ans = cnt;
  }
  cout << ans << endl;
  return 0;
}

int count(unsigned int n) {
  int count = 0;
  while(n != 0) {
    if((n & 1) == 1) {
      count++;
    }
    n >>= 1;
  }
  return count;
}