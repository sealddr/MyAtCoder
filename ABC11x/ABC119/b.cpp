#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

const double BTCJPY = 380000.0;
int main() {
  int n;
  cin >> n;
  double sum = 0.0;
  rep(i, n) {
    double x;
    string u;
    cin >> x >> u;
    if(u == "BTC") x *= BTCJPY;
    sum += x;
  }
  printf("%.10f\n", sum);
  return 0;
}