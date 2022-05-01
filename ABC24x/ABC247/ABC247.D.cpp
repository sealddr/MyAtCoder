#include <iostream>
#include <string>
#include <queue>
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;
int main(void){
    int q;
    cin >> q;
    int qcode;
    ll c, x;
    ll nowc = 0, nowx =-1;
    queue<pair<ll,ll>> que;
    rep (i,q){
        cin >> qcode;
        if(qcode == 1) {
            cin >> x >> c;
            que.push(make_pair(x,c));
        }else{
            ll ans = 0;
            cin >> c;
            while (c > 0){
                if(nowc == 0) {
                    pair<ll,ll> p = que.front(); que.pop();
                    nowx = p.first;
                    nowc = p.second;
                }
                if(c <= nowc) {ans += nowx * c; nowc -= c; c = 0; }
                else { ans += nowx * nowc; c -= nowc; nowc = 0;}
            }
            cout << ans << endl;
        }
    }
}
