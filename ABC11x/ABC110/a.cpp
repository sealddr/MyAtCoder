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
  int a, b, c;
  cin >> a >> b >> c;
  if(a < b) swap(a, b);
  if(a < c) swap(a, c);
  cout << 10 * a + b + c << endl;
  return 0;
}