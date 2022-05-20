#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int n, m, q;
const int maxq = 55;
vector<int> a(maxq), b(maxq), c(maxq), d(maxq);

template <typename T>
bool chmax(T &a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll dfs(int idx, int now, vector<int> A){
    A.push_back(now);
    if(idx + 1 == n){
        ll sum = 0;
        rep(i, q) if(A[b[i]] - A[a[i]] == c[i]) sum += d[i];
        return sum;
    }
    ll res = 0;
    for(int next = now; next <= m; ++next)
        chmax(res, dfs(idx + 1, next, A));
    return res;
}

int main() {
    cin >> n >> m >> q;
    rep(i, q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i];
        --b[i];
    }
    vector<int> A;
    ll ans = 0;
    for(int a0 = 1; a0 <= m; a0++){
        chmax(ans, dfs(0, a0, A));
    }
    cout << ans << endl;
}