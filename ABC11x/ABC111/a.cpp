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
  if(s[0] == '1')
    cout << '9';
  else
    cout << '1';
  if(s[1] == '1')
    cout << '9';
  else
    cout << '1';
  if(s[2] == '1')
    cout << '9';
  else
    cout << '1';
  cout << endl;
  return 0;
}