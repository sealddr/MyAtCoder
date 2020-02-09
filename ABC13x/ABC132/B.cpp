#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  int cnt = 0;
  rep(i, n - 2) {
    if(p[i] < p[i + 1] && p[i + 1] < p[i + 2])
      cnt++;
    else if(p[i] > p[i + 1] && p[i + 1] > p[i + 2])
      cnt++;
  }
  cout << cnt << endl;
  return 0;
}