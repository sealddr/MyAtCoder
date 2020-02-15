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
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<int> x(N), y(M);
  rep(i, N) cin >> x[i];
  rep(j, M) cin >> y[j];
  x.push_back(X), y.push_back(Y);
  sort(all(x)), sort(all(y));
  if(x[N] >= y[0])
    cout << "War" << endl;
  else
    cout << "No War" << endl;
  return 0;
}