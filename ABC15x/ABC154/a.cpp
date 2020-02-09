#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  string s, t;
  int a, b;
  string u;
  cin >> s >> t >> a >> b >> u;
  if(s == u) a--;
  if(t == u) b--;
  cout << a << ' ' << b << endl;
  return 0;
}