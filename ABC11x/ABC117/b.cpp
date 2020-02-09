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
  int n;
  cin >> n;
  vector<int> L(n);
  rep(i, n) cin >> L[i];
  sort(all(L));
  int maxL = L[n - 1];
  int sum = 0;
  rep(i, n - 1) sum += L[i];
  if(sum > maxL) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}