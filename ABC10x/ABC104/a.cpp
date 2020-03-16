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
  int R;
  cin >> R;
  if(R < 1200)
    cout << "ABC" << endl;
  else if(R < 2800)
    cout << "ARC" << endl;
  else
    cout << "AGC" << endl;
  return 0;
}