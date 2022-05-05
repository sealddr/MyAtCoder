#include<bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i]; 
    
    unordered_map<int,ll> cnta;
    rep(i,n) cnta[a[i]]++;
    
    unordered_map<int,ll> mp,mpp;
    rep(i,n) {
        if(cnta[a[i]] > 2) mpp[a[i]] =  (cnta[a[i]] - 1) * (cnta[a[i]] - 2) / 2;
        if(cnta[a[i]] > 1) mp[a[i]] =  cnta[a[i]] * (cnta[a[i]] - 1) / 2;
    }

    ll sum = 0;
    for(auto x : mp) sum += x.second;
    rep(i,n) cout << sum - mp[a[i]] + mpp[a[i]] << endl;

}