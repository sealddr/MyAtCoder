#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << min(a + b, min(b + c, c + a)) << endl;
  return 0;
}