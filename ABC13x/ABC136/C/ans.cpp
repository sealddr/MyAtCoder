#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
const ll INF = 1000000005;
int main(void) {
  int n;
  cin >> n;
  vector<ll> h(n);
  rep(i, n) cin >> h[i];
  reverse(h.begin(), h.end());
  ll minh = INF;
  rep(i, n) {
    if(h[i] > minh + 1) {
      cout << "No" << endl;
      return 0;
    }
    minh = min(minh, h[i]);
  }
  cout << "Yes" << endl;
  return 0;
}