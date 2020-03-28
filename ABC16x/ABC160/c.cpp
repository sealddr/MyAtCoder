#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
const int INF = 1100100;
int main() {
  int k, n;
  cin >> k >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  int x = k + A[0] - A[n - 1];
  rep(i, n - 1) x = (max(x, A[i + 1] - A[i]));
  cout << k - x << endl;
  return 0;
}