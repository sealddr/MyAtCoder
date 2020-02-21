#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int k;
  cin >> k;
  int no, ne;
  no = (k + 1) / 2;
  ne = k / 2;
  cout << no * ne << endl;
  return 0;
}