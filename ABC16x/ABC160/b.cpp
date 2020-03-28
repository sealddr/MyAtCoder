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
  int x;
  cin >> x;
  int n = x / 500;
  int m = (x - 500 * n) / 5;
  cout << 1000 * n + 5 * m << endl;
  return 0;
}