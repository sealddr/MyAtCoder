#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

bool f(ll x) {
  vector<int> vec = {3, 5, 7};
  vector<bool> appears(3);
  while(x) {
    rep(i, 3) if(x % 10 == vec[i]) appears[i] = true;
    x /= 10;
  }
  bool res = true;
  rep(i, 3) res &= appears[i];
  return res;
}

int dfs(ll x, ll n) {
  int res = 0;
  if(x > n) return 0;
  if(f(x)) res++;
  rep(i, 3) res += dfs(x * 10 + 2 * i + 3, n);
  return res;
}

int main() {
  ll n;
  cin >> n;
  cout << dfs(0, n) << endl;
  return 0;
}