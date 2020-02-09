#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

const int MAXN = 1000005;
int main() {
  int s;
  cin >> s;
  vector<int> a(MAXN);
  bool ok = false;
  int i = 1;
  a[0] = 0;
  a[1] = s;
  while(!ok) {
    i++;
    if(a[i - 1] % 2 == 0)
      a[i] = a[i - 1] / 2;
    else
      a[i] = 3 * a[i - 1] + 1;
    rep(j, i) if(a[j] == a[i]) ok = true;
  }
  cout << i << endl;
  return 0;
}