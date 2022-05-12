#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ivl(m);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        ivl[i] = make_pair(b, a);
    }
    sort(ivl.begin(), ivl.end());
    int ans = 0;
    int r = -1;
    rep(i,m){
        if(r > ivl[i].second) continue;
        r = ivl[i].first;
        ans ++;
    }
    cout << ans << endl;
}