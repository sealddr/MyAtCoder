#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  int cnt = 0;
  rep(i, n) if(p[i] != i + 1) cnt++;
  if(cnt == 2 || cnt == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}