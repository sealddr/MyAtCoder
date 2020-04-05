#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
const int INF = 999;
int main() {
  vector<int> a(3);
  rep(i, 3) cin >> a[i];
  vector<int> P(9);
  int n = a[0] + a[1] + a[2];
  rep(i, 9) {
    if(i < n)
      P[i] = i;
    else
      P[i] = INF;
  }
  int cnt = 0;
  do {
    if(a[0] == 1 && P[1] < INF) continue;
    if(a[0] == 2 && P[2] < INF) continue;
    if(a[1] == 1 && P[4] < INF) continue;
    if(a[1] == 2 && P[5] < INF) continue;
    if(a[2] == 1 && P[7] < INF) continue;
    if(a[2] == 2 && P[8] < INF) continue;
    if(P[0] == INF) continue;
    if(P[3] == INF) continue;
    if(P[6] == INF) continue;
    if(P[1] == INF && P[2] < INF) continue;
    if(P[4] == INF && P[5] < INF) continue;
    if(P[7] == INF && P[8] < INF) continue;
    if(P[0] > P[1]) continue;
    if(P[1] > P[2]) continue;
    if(P[3] > P[4]) continue;
    if(P[4] > P[5]) continue;
    if(P[6] > P[7]) continue;
    if(P[7] > P[8]) continue;
    if(P[0] > P[3]) continue;
    if(P[3] > P[6]) continue;
    if(P[1] > P[4]) continue;
    if(P[4] > P[7]) continue;
    if(P[2] > P[5]) continue;
    if(P[5] > P[8]) continue;
    cnt++;
  } while(next_permutation(all(P)));
  cout << cnt << endl;
  return 0;
}