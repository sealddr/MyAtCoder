#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main() {
  string s;
  cin >> s;
  vector<int> cnt(2);
  rep(i, s.size()) cnt[s[i] - '0']++;
  cout << 2 * min(cnt[0], cnt[1]) << endl;
  return 0;
}