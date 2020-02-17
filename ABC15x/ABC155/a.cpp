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
  int a, b, c;
  cin >> a >> b >> c;
  if(a == b && b == c)
    cout << "No" << endl;
  else if(a != b && b != c && c != a)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}