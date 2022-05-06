#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

template <typename T>
bool chmin(T& a, const T& b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}

int cntValid(ll bm) {
  int res = 0;
  while(bm) {
    res += (bm & 1);
    bm = bm >> 1;
  }
  return res;
}

bool isValidAt(int i, ll bm) {
  return (bm >> i) & 1;
}

bool anyofSumGt(vector<int> v, vector<int> w, int x) {
  bool res = false;
  int sz = v.size();
  rep(i, sz) res = (res || (v[i] + w[i] > x));
  return res;
}

int breakChocolate(int h, int w, int k, vector<string> s, ll bm) {
  int res = cntValid(bm);
  bm = bm * 2 + 1;

  vector<vector<int>> hbChocolates;    // horizontally broken
  int jthpiece = -1;
  rep(j, h) {
    if(isValidAt(j, bm)) {
      vector<int> piecedChocolate(w);
      rep(i, w) piecedChocolate[i] = s[j][i] - '0';
      hbChocolates.push_back(piecedChocolate);
      jthpiece++;
    } else {
      rep(i, w) hbChocolates[jthpiece][i] += s[j][i] - '0';
    }
  }
  int pieces = hbChocolates.size();
  rep(j, pieces) rep(i,w) if(hbChocolates[j][i] > k) return 10000; 
  // greedy now spotted virtically broken
  vector<vector<int>> nowvbChocolates(2, vector<int>(pieces));
  rep(j, pieces) {
    nowvbChocolates[0][j] = hbChocolates[j][0];
    nowvbChocolates[1][j] = hbChocolates[j][1];
  }
  rep(i, w - 1) {
    if(anyofSumGt(nowvbChocolates[0], nowvbChocolates[1], k)) {
      // virtically break!
      res++;
      rep(j, pieces) { nowvbChocolates[0][j] = nowvbChocolates[1][j]; }
    } else {
      rep(j, pieces) { nowvbChocolates[0][j] += nowvbChocolates[1][j]; }
    }
    rep(j, pieces) { nowvbChocolates[1][j] = hbChocolates[j][i + 2]; }
  }
  return res;
}

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  int ans = 10000;
  for(ll bm = 0; bm < pow(2, h - 1); bm++) {
    chmin(ans, breakChocolate(h, w, k, s, bm));
  }
  cout << ans << endl;
}