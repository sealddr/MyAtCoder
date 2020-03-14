#include <iostream>
using namespace std;
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long d = c - a - b;
  if(d > 0 && d * d > 4LL * a * b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}