#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  ll n, k;
  cin >> n >> k;
  ll x = n % k;
  ll y = -n % k;
  y += k;
  cout << min(x, y) << endl;
  return 0;
}