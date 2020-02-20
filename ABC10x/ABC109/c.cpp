#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> X(n);
  rep(i, n) {
    int nx;
    cin >> nx;
    X[i] = abs(nx - x);
  }
  int g = X[0];
  rep(i, n) g = gcd(g, X[i]);
  cout << g << endl;
  return 0;
}