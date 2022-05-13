#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
#define mod 1000000007

ll sum(ll l, ll r) {
    return ((r - l + 1) * (r + l) / 2);
}

int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for(ll i = k; i <= n + 1; i++)
        ans =
          (ans + (sum(n - i + 1, n) + 1) - sum(0, i - 1))
          % mod;
    cout << ans << endl;
}