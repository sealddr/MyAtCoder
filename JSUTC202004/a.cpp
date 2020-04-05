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
  int s, l, r;
  cin >> s >> l >> r;
  if(s < l)
    cout << l << endl;
  else if(r < s)
    cout << r << endl;
  else
    cout << s << endl;
  return 0;
}