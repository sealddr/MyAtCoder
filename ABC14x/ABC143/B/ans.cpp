#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(void) {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) cin >> d[i];
  int sum = 0;
  rep(i, n) rep(j, i) {
    sum += d[i] * d[j];
  }
  cout << sum << endl;
  return 0;
}