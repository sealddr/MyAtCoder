#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int N, K, Q;
  cin >> N >> K >> Q;
  vector<int> S(N, 0);
  int A;
  for(int i = 0; i < Q; i++) {
    cin >> A;
    S[A - 1]++;
  }
  for(int i = 0; i < N; i++) {
    if(S[i] + K - Q <= 0) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}