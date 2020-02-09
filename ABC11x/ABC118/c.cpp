#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll g = a[0];
  rep(i, n - 1) g = gcd(g, a[i + 1]);
  cout << g << endl;
  return 0;
}