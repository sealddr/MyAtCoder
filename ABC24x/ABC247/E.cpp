#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)


int main(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll idxX = -1L, idxY = -1L, idxZ = -1L;
    ll ans = 0;
    for(ll i = 0LL;i < n; i++){
        if(x == a[i]) idxX = i;
        if(y == a[i]) idxY = i;
        if(a[i] < y || x < a[i]) idxZ = i;
        ans += max(0LL, min(idxX, idxY) - idxZ);
    }
    cout << ans << endl;
}
