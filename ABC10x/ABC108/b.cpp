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
  vector<int> x(4), y(4);
  cin >> x[0] >> y[0] >> x[1] >> y[1];
  int vx, vy;
  vx = x[1] - x[0];
  vy = y[1] - y[0];
  x[2] = x[1] - vy, y[2] = y[1] + vx;
  x[3] = x[2] - vx, y[3] = y[2] - vy;
  cout << x[2] << ' ';
  cout << y[2] << ' ';
  cout << x[3] << ' ';
  cout << y[3] << endl;
  return 0;
}