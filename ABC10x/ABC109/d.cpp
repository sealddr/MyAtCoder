#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> a(H, vector<int>(W));
  rep(i, H) rep(j, W) cin >> a[i][j];
  vector<P> from;
  vector<P> to;
  rep(i, H) rep(j, W - 1) {
    if(a[i][j] % 2 == 1) {
      from.push_back(make_pair(i, j));
      to.push_back(make_pair(i, j + 1));
      --a[i][j];
      ++a[i][j + 1];
    }
  }
  rep(i, H - 1) if(a[i][W - 1] % 2 == 1) {
    from.push_back(make_pair(i, W - 1));
    to.push_back(make_pair(i + 1, W - 1));
    --a[i][W - 1];
    ++a[i + 1][W - 1];
  }
  int n = from.size();
  cout << n << endl;
  rep(i, n) {
    cout << ++from[i].first << ' ';
    cout << ++from[i].second << ' ';
    cout << ++to[i].first << ' ';
    cout << ++to[i].second << endl;
  }
  return 0;
}