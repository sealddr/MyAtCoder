#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int N;
  cin >> N;
  vector<int> A(N + 1);
  A[0] = -1;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  vector<int> B(N + 1);
  B[0] = -1;
  for(int i = 1; i <= N; i++) {
    cin >> B[i];
  }
  vector<int> C(N + 1);
  C[0] = -1;
  for(int i = 1; i < N; i++) {
    cin >> C[i];
  }
  int ans = 0;
  for(int i = 1; i <= N; i++) {
    ans += B[i];
  }
  for(int i = 1; i < N; i++) {
    if(1 == A[i + 1] - A[i]) {
      ans += C[A[i]];
    }
  }
  cout << ans << endl;
  return 0;
}