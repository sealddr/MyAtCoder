#include <iostream>
using namespace std;

int gcd(int a, int b) {
  if(a < b) {
    swap(a, b);
  }
  if(0 == a % b) {
    return b;
  }
  return gcd(b, a % b);
}

int main(void) {
  int a, b;
  cin >> a >> b;
  int g = gcd(a, b);
  cout << (long long)a * (long long)b / g << endl;
  return 0;
}