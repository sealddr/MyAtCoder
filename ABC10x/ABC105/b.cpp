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
  int n;
  cin >> n;
  for(int i = 0; i <= n / 4; i++) {
    int r = n - i * 4;
    if(r % 7 == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}