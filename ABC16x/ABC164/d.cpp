#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
    string s;
    cin >> s;
    int mod10pow[200010];
    mod10pow[0] = 1;
    rep(k,200005) mod10pow[k + 1] = (10 * mod10pow[k]) % 2019;
    
    ll cntmod[2019];
    int n = s.length();
    int mods[n+1];
    mods[0] = 0;
    cntmod[0] = 1;
    reverse(s.begin(),s.end());
    rep(i, n) {
        mods[i + 1] = ((s[i] - '0') * mod10pow[i] + mods[i]) % 2019;
        cntmod[mods[i + 1]]++;
    }

    ll ans = 0;
    rep(i, 2019){
        ll x = cntmod[i];
        ans += x * (x - 1) / 2;
    }
    cout << ans << endl;
}