#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n, m;
  cin >> n >> m;
  unordered_map<int, int> mp;
  rep(i, n) mp[i] = -1;
  rep(i, m) {
    int s, c;
    cin >> s >> c;
    s = n - s;
    if(mp[s] != -1 && mp[s] != c) {
      cout << "-1" << endl;
      return 0;
    }
    mp[s] = c;
  }

  int x = 0;
  int b = 1;
  for(int keta = 0; keta < n; keta++) {
    int c = mp[keta];
    if(c == -1) {
      if(keta != 0 && keta == n - 1)
        c = 1;
      else
        c = 0;
    }
    x += c * b;
    b *= 10;
  }

  int y = 0;
  b = 1;
  for(int keta = 0; keta < n; keta++) {
    y += 9 * b;
    b *= 10;
  }
  if(x > y) {
    cout << "-1" << endl;
    return 0;
  }

  int z = 1;
  for(int keta = 0; keta < n - 1; keta++) z *= 10;
  if(n == 1) z = -1;

  if(x < z) {
    cout << "-1" << endl;
    return 0;
  }

  cout << x << endl;
  return 0;
}
