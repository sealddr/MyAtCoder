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
  int n, k;
  string s;
  cin >> n >> k >> s;
  s[k - 1] = tolower(s[k - 1]);
  cout << s << endl;
  return 0;
}