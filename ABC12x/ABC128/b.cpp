#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, int> P;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n;
  cin >> n;
  map<P, int> mp;
  rep(i, n) {
    string s;
    int p;
    cin >> s >> p;
    P pr = make_pair(s, -p);
    mp[pr] = i + 1;
  }
  for(auto x : mp) cout << x.second << endl;
  return 0;
}