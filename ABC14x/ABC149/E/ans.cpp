#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void) {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end(), greater<int>());
  long long ans = 0;

  return 0;
}