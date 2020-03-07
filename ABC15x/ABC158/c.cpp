#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int a, b;
  cin >> a >> b;
  for(int x = 1; x <= 1250; x++) {
    if((8 * x) / 100 == a && (10 * x) / 100 == b) {
      cout << x << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}