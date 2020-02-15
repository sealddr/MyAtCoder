#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  vector<int> nums(26, -1);
  vector<int> numt(26, -1);

  rep(i, n) {
    int a = s[i] - 'a';
    int b = t[i] - 'a';

    if(nums[a] != -1 || numt[b] != -1) {
      if(nums[a] != b || numt[b] != a) {
        cout << "No" << endl;
        return 0;
      }
    }
    nums[a] = b;
    numt[b] = a;
  }
  cout << "Yes" << endl;

  return 0;
}