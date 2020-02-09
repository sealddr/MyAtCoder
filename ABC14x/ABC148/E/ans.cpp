#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  long long n;
  cin >> n;
  if(1 == n % 2) {
    cout << 0 << endl;
    return 0;
  }

  long long count = 0;
  for(long long k = n / 10; k > 0; k /= 5) {
    count += k / 5;
  }
  cout << (n / 10) + count << endl;
  return 0;
}