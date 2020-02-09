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
  bool HEISEI = true;
  if(s[5] > '0')
    HEISEI = false;
  else if(s[6] > '0' + 4)
    HEISEI = false;

  if(HEISEI)
    cout << "Heisei" << endl;
  else
    cout << "TBD" << endl;
  return 0;
}