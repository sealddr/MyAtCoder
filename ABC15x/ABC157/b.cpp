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
  vector<vector<int>> A(3, vector<int>(3));
  rep(i, 3) rep(j, 3) cin >> A[i][j];
  int n;
  cin >> n;

  rep(k, n) {
    int b;
    cin >> b;
    rep(i, 3) rep(j, 3) if(A[i][j] == b) A[i][j] = 0;
  }
  string ans = "No";
  rep(i, 3) {
    int x = 0;
    rep(j, 3) x |= A[i][j];
    if(x == 0) ans = "Yes";
  }
  rep(j, 3) {
    int x = 0;
    rep(i, 3) x |= A[i][j];
    if(x == 0) ans = "Yes";
  }
  {
    int x = 0;
    rep(i, 3) x |= A[i][i];
    if(x == 0) ans = "Yes";
  }
  {
    int x = 0;
    rep(i, 3) x |= A[i][2 - i];
    if(x == 0) ans = "Yes";
  }
  cout << ans << endl;
  return 0;
}