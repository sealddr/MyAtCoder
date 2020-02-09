#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  vector<int> v(n);
  int a;
  for(int i = 0; i < n; i++) {
    cin >> a;
    v[a - 1] = i;
  }
  cout << v[0] + 1;
  for(int i = 1; i < n; i++) {
    cout << ' ' << v[i] + 1;
  }
  cout << endl;
  return 0;
}