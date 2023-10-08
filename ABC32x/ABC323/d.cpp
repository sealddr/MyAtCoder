#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    map<ll, ll> mp;

    rep(i ,n){
        ll s, c;
        cin >> s >> c;
        mp[s] += c;
    }

    int ans = 0;
    while(mp.size()){
        auto it = mp.begin();
        auto s = it->first;
        auto c = it->second;
        mp.erase(it);
        ans += c % 2;
        s *= 2;
        c /= 2;
        if(c) mp[s] += c;
    }
    cout << ans << endl;
}