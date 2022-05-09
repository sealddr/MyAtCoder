#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

vector<int> getDivs(int n) {
    vector<int> divs;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            divs.push_back(i);
            if(i != n/i)divs.push_back(n / i);
        }
    }
    return divs;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    unordered_map<int, int> mp;
    rep(i, n) mp[a[i]]++;

    ll ans = 0;
    rep(i, n) {
        vector<int> divs = getDivs(a[i]);
        for(auto x : divs) {
            if(mp[x] && mp[a[i]/x]) ans+= 1LL*mp[x] * mp[a[i]/x];
        }
    }
    cout << ans << endl;
}