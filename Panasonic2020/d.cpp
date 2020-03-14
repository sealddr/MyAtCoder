#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int n;
void dfs(string s, char c, int len) {
  if(len == n) {
    cout << s << endl;
    return;
  }
  rep(i, c - 'a' + 2) {
    char nc = 'a' + i;
    dfs(s + nc, max(c, nc), len + 1);
  }
  return;
}
int main() {
  cin >> n;
  dfs("a", 'a', 1);
  return 0;
}