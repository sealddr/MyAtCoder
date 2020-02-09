#include <iostream>
#include <vector>
using namespace std;
long long gcd(long long a, long long b) {
  if(b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  return a * b / gcd(a, b);
}

int f(int n) {
  if(n % 2 == 0) {
    return 1 + f(n / 2);
  }
  return 0;
}

int ceil(int a, int b) {
  return (a + b - 1) / b;
}

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] /= 2;
  }

  int t = f(a[0]);
  for(int i = 1; i < n; i++) {
    if(t != f(a[i])) {
      cout << 0 << endl;
      return 0;
    }
  }

  for(int i = 0; i < n; i++) {
    a[i] >>= t;
  }
  m >>= t;

  long long x = a[0];
  for(int i = 1; i < n; i++) {
    x = lcm(x, a[i]);
    if(m < x) {
      cout << 0 << endl;
      return 0;
    }
  }

  cout << ceil(m, 2 * x) << endl;
  return 0;
}