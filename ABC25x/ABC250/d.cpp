#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MAXQ 1000000

vector<int> eratosthenes(int n) {
    vector<int> parr(n + 1);
    parr[0] = 0;
    parr[1] = 0;
    for(int i = 2; i <= n; i++) parr[i] = 1;
    for(int i = 2; i * i <= n; i++) {
        if(!parr[i]) continue;
        for(int j = 0; i * (j + 2) <= n; j++)
            parr[i * (j + 2)] = 0;
    }
    return parr;
}

int main() {
    vector<int> parr = eratosthenes(MAXQ);
    vector<ll> cnt(MAXQ + 1);
    for(int i = 1; i <= MAXQ; i++)
        cnt[i] = cnt[i - 1] + parr[i];
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll q = 2; q * q * q <= n; q++) {
        if(!parr[q]) continue;
        ll p = n / (q * q * q);
        if(p >= q) p = q - 1;
        ans += cnt[p];
    }
    cout << ans << endl;
}
