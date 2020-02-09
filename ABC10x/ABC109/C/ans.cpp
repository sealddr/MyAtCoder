#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
  string S;
  long long K;
  cin >> S >> K;
  int cnt = 0;
  char nc;
  for(int i = 0; i < S.size(); i++) {
    if(0 < S[i] - '1') {
      nc = S[i];
      break;
    }
    cnt++;
  }
  if(K <= cnt) {
    cout << '1' << endl;
    return 0;
  }
  cout << nc << endl;
  return 0;
}