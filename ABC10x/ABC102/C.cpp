#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i] -= i;
    }
    sort(all(a));
    ll x = a[n/2];
    ll ans = 0;
    rep(i,n) ans += abs(a[i] - x);
    cout << ans << endl; 
}
