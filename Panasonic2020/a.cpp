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
  vector<int> vec = {1, 1,  1, 2, 1,  2, 1, 5, 2, 2, 1,
                     5, 1,  2, 1, 14, 1, 5, 1, 5, 2, 2,
                     1, 15, 2, 2, 5,  4, 1, 4, 1, 51};
  int k;
  cin >> k;
  k--;
  cout << vec[k] << endl;
  return 0;
}