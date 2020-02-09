#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int k = 1;
  int count = 0;
  bool ok = false;
  for(int i = 0; i < n; i++) {
    if(k == a[i]) {
      k++;
      ok = true;
    } else {
      count++;
    }
  }
  if(!ok) {
    cout << "-1" << endl;
    return 0;
  }
  cout << count << endl;
  return 0;
}