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
  int n;
  cin >> n;
  vector<int> R, B;
  rep(i, n) {
    int x;
    char c;
    cin >> x >> c;
    if(c == 'R')
      R.push_back(x);
    else
      B.push_back(x);
  }
  sort(all(R)), sort(all(B));
  for(auto r : R) cout << r << endl;
  for(auto b : B) cout << b << endl;
  return 0;
}