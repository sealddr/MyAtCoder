#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll h;
  cin >> h;
  int t = 0;
  for(; h > 0; h >>= 1, t++) {
  }
  cout << ((1LL << t) - 1) << endl;
  return 0;
}