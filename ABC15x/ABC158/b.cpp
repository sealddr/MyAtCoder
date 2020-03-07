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
  ll n, a, b;
  cin >> n >> a >> b;
  cout << a * (n / (a + b))
            + min(a, n - (a + b) * (n / (a + b)))
       << endl;
  return 0;
}