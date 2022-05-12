#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define INF 250000005LL
typedef long long ll;

template <typename T>
bool chmin(T& a, const T& b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<vector<int>> d(c, vector<int>(c));
    rep(j, c) rep(i, c) cin >> d[j][i];
    vector<vector<int>> col(n, vector<int>(n));
    rep(j, n) rep(i, n) {
        cin >> col[j][i];
        --col[j][i];
    }
    ll sumds[30][3];
    rep(ic, c) rep(i, 3) sumds[ic][i] = 0;
    rep(ic, c) rep(i, n) rep(j, n) sumds[ic][(i + j) % 3] +=
      d[col[j][i]][ic];
    ll ans = INF;
    rep(c0, c) rep(c1, c) rep(c2, c) {
        if(c0 == c1) continue;
        if(c1 == c2) continue;
        if(c2 == c0) continue;
        chmin(ans,
              sumds[c0][0] + sumds[c1][1] + sumds[c2][2]);
    }
    cout << ans << endl;
}