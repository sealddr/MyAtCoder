#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int cntValid(vector<ll> vec, int keta) {
    int res = 0;
    for(auto x : vec)
        if((x >> keta) & 1 == 1) res++;
    return res;
}

bool odd(int n) {
    if(n % 2 == 1) return true;
    return false;
}

int bitsum(vector<vector<int>> cntValids, int n, int keta) {
    return (cntValids[keta][0] + cntValids[keta][1]) * n;
}

int numCarry(vector<vector<int>> cntValids, int n, int keta) {
    return bitsum(cntValids, n, keta) / 2;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    vector<vector<int>> cntValids(28, vector<int>(2));
    rep(keta, 28) {
        cntValids[keta][0] = cntValid(a, keta);
        cntValids[keta][1] = cntValid(b, keta);
    }

    ll ans = 0;
    rep(keta, 28) if(odd(bitsum(cntValids, n, keta))) ans += (1 << keta);
    ll carrys = 0;
    rep(keta, 28) {
        rep(i, n) {
            carrys = carrys ^ cntValids[keta][0] * 1 << f(b[i] + 1);
        }
    }
    cout << ans << endl;
    cout << sumcarry << endl;
    ans = ans + sumcarry;
    cout << ans << endl;
}