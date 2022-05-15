#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAXN 300005
#define INF 1000000005
typedef long long ll;

ll dp[MAXN][4];
template <typename T>
bool chmin(T &a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    dp[0][0] = INF;
    dp[0][1] = a[0];
    dp[0][2] = a[n-1];
    dp[0][3] = a[n-1] + a[0];

    for(int i = 1; i < n - 1; i++){
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = min (dp[i - 1][0] + a[i], dp[i - 1][1] + a[i]);
        dp[i][2] = dp[i - 1][3];
        dp[i][3] = min (dp[i - 1][2] + a[i], dp[i - 1][3] + a[i]);
    }

    ll ans = min(dp[n - 2][0] + a[n - 2], dp[n - 2][0] + a[n - 1]);
    chmin(ans,dp[n - 2][1]);
    chmin(ans,dp[n - 2][2]);
    chmin(ans,dp[n - 2][3]);
    cout << ans << endl;
}
