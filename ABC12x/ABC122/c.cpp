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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<int> cntACs;
  int cnt = 0;
  cntACs.push_back(cnt);
  cntACs.push_back(cnt);
  for(int i = 1; i < n; i++) {
    if(s[i - 1] == 'A' && s[i] == 'C') cnt++;
    cntACs.push_back(cnt);
  }
  vector<P> ivl(q);
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    ivl[i] = make_pair(l, r);
  }

  rep(i, q) {
    int ans = cntACs[ivl[i].second] - cntACs[ivl[i].first];
    cout << ans << endl;
  }

  return 0;
}