#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int main(void) {
  int N, M;
  cin >> N >> M;
  multiset<int> A;
  int a;
  for(int i = 0; i < N; i++) {
    cin >> a;
    A.insert(a);
  }

  for(int i = 0; i < M; i++) {
    auto itr = A.end();
    itr--;
    int aa = (*itr) / 2;
    A.erase(itr);
    A.insert(aa);
  }
  long long ans = 0;
  for(auto itr = A.begin(); itr != A.end(); itr++) {
    ans += *itr;
  }
  cout << ans << endl;
  return 0;
}
