#include <iostream>
#include <string>
#include <queue>
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;

ll pow (ll n, int k){
    if(k==0) return 1;
    return n * pow (n, k - 1);
}

ll x (ll a, ll b){
    return a * a * a + a * a * b + a * b * b + b * b * b;
}

bool pred (ll mid, ll n, ll a){
    return n <= x(a, mid); 
}

ll bin_search (ll ok, ll ng, ll n, ll a){
    while(abs(ok - ng)> 1 ){
        ll mid = abs(ok + ng) / 2;
        if(pred(mid, n, a)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main(){
    ll n;
    cin >> n;
    ll ans = pow(10,18) + 1;
    for(ll a = 0L; a <= 1000000L && a <= n; a++){
        ll ok = pow(10,6);
        ll ng = -1L;
        ll b = bin_search (ok,ng,n,a);
        ans = min(ans, x(a, b));
    }
    cout << ans << endl;
}