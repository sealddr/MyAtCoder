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
  string s;
  cin >> s;
  int n = s.size();
  bool ok = true;
  if(n % 2 == 1) ok = false;
  for(int i = 0; i < n; i += 2) {
    if(s[i] != 'h') ok = false;
    if(s[i + 1] != 'i') ok = false;
  }
  if(ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}