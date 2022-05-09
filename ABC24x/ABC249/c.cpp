#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

bool isValid(ll bm, int i) {
    return (bm >> i) & 1;
}

template <typename T>
bool chmax(T& a, const T& b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    int ans = 0;
    for(ll bm = 0; bm < pow(2, n); bm++) {
        vector<int> cnt(26);
        rep(i, n) {
            if(isValid(bm, i)) {
                string now = s[i];
                rep(j, now.length()) {
                    cnt[now[j] - 'a']++;
                }
            }
        }
        int cntt = 0;
        rep(c, 26) if(cnt[c] == k) cntt++;
        chmax(ans, cntt);
    }
    cout << ans << endl;
}