#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void) {
  int n, k;
  cin >> n >> k;
  int r, s, p;
  cin >> r >> s >> p;
  string t;
  cin >> t;
  int count[3] = {0, 0, 0};
  vector<bool> change(n);
  for(int i = 0; i < n; i++) {
    change[i] = false;
  }
  for(int i = 0; i < n; i++) {
    int j = i - k;
    switch(t[i]) {
      case 'r':
        if(j < 0 || t[j] != 'r'
           || (t[j] == 'r' && change[j])) {
          count[0]++;
        } else if(j >= 0 && t[j] == 'r') {
          change[i] = true;
        }
        break;
      case 's':
        if(j < 0 || t[j] != 's'
           || (t[j] == 's' && change[j])) {
          count[1]++;
        } else if(j >= 0 && t[j] == 's') {
          change[i] = true;
        }
        break;
      case 'p':
        if(j < 0 || t[j] != 'p'
           || (t[j] == 'p' && change[j])) {
          count[2]++;
        } else if(j >= 0 && t[j] == 'p') {
          change[i] = true;
        }
        break;
    }
  }
  cout << count[0] * p + count[1] * r + count[2] * s
       << endl;
  return 0;
}