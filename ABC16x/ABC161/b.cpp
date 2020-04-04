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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  int sum = 0;
  rep(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  int cnt = 0;
  rep(i, n) if(a[i] >= (sum + 4 * m - 1) / (4 * m)) cnt++;
  if(cnt >= m)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}