#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)

const ll INF = 1e15 + 5;
int main() {
  ll n;
  cin >> n;
  ll mcap = INF;
  rep(i, 5) {
    ll cap;
    cin >> cap;
    mcap = min(mcap, cap);
  }
  cout << (n + mcap - 1) / mcap + 4 << endl;
}