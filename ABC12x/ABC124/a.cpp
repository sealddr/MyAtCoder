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
  if(a < b) swap(a, b);
  cout << max(2 * a - 1, a + b) << endl;
  return 0;
}