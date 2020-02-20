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
  int n;
  cin >> n;
  vector<string> S(n);
  rep(i, n) cin >> S[i];

  string s = S[0];
  for(int i = 1; i < n; i++) {
    string ns = S[i];
    if(*(--s.end()) != *ns.begin()) {
      cout << "No" << endl;
      return 0;
    }
    s = ns;
  }

  unordered_map<string, int> mp;
  rep(i, n) { mp[S[i]]++; }
  for(auto x : mp) {
    if(x.second > 1) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}