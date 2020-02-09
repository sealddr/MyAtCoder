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
  int n, k;
  string s;
  cin >> n >> k >> s;

  vector<int> acc;
  int bt = 1;
  int cnt = 0;
  rep(i, n) {
    if(s[i] != (char)(bt + '0')) {
      acc.push_back(cnt);
      bt ^= 1;
      cnt = 1;
    } else {
      cnt++;
    }
  }
  if(cnt != 0) acc.push_back(cnt);
  if(!bt) acc.push_back(0);

  int m = (int)acc.size();
  int d = 2 * k + 1;
  int ans = 0;

  int left = 0;
  int right = 0;
  int tmp = 0;

  for(int i = 0; i < m; i += 2) {
    int nextleft = i;
    int nextright = min(i + d, m);
    while(nextleft > left) {
      tmp -= acc[left];
      left++;
    }
    while(nextright > right) {
      tmp += acc[right];
      right++;
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;

  return 0;
}
