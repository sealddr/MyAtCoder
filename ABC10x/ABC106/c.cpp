#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define dbg(x) cerr << #x << ": " << x << endl

int main() {
  string S;
  ll K;
  cin >> S >> K;
  ll i = 0;
  while(1) {
    if(S[i] == '1')
      K--;
    else
      break;
    if(K <= 0) break;
    i++;
  }
  cout << S[i] << endl;
  return 0;
}