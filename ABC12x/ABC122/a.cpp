#include <iostream>
#include <string>
#include <unordered_map>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
int main() {
  char b;
  cin >> b;
  char ans;
  string s = "ACGT", t = "TGCA";
  unordered_map<char, char> mp;
  rep(i, 4) mp[s[i]] = t[i];
  cout << mp[b] << endl;
  return 0;
}