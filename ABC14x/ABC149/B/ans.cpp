#include <iostream>
using namespace std;
long long max(long long a, long long b) {
  if(a >= b) {
    return a;
  }
  return b;
}

int main(void) {
  long long a, b, k;
  cin >> a >> b >> k;
  cout << max(a - k, 0) << ' ' << max(b - max(k - a, 0), 0)
       << endl;
  return 0;
}