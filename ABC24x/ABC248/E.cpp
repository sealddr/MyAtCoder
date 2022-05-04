#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

typedef pair<ll, ll> P;
typedef pair<P, P> Line;
#define rep(i, n) for(int i = 0; i < (n); ++i)

ll gcd(ll x, ll y){
    if(y == 0) return x;    
    if(x < y) return gcd (y, x);
    return gcd(y, x % y);
}

int main(){
    ll n, k;
    cin >> n >> k;
    if(k == 1) {
        cout << "Infinity" << endl; return 0;
    }

    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    vector<pair<pair<P, P>,int>> lines; 
    rep(i, n) rep(j, i){
        ll dx = x[i] - x[j], dy = y[i] - y[j];
        if(dx == 0 && dy == 0) {
            cout << "Infinity" << endl; return 0;
        }
        ll g = gcd(abs(dx),abs(dy));
        dx /= g; dy /=g;

        if(dx < 0 || dx == 0 && dy < 0){ dx = -dx; dy = -dy; }
        ll s, t;
        if(dx == 0) { s = x[i]; t = 0; }
        else if(dy == 0) { s = y[i]; t = 0; }
        else { 
            s = y[i] * dx - x[i] * dy; t = dx; 
            ll gg = gcd(abs(s), abs(t));
            s /= gg; t /= gg;
        }
        if(t < 0){ s = -s; t = -t; }
        
        int sz = lines.size();
        bool ok = false;
        rep(i,sz){
            pair<P,P> line = lines[i].first;
            P sl = line.first;
            P it = line.second;
            if(sl.first == dx && sl.second == dy && it.first == s && it.second ==t) ok = true;
        }
        if(!ok) lines.push_back(make_pair(make_pair(P(dx, dy), P(s, t)), 0));
    }
    int sz = lines.size();
    rep(i,n) rep(j, sz){  
            pair<P,P> line = lines[j].first;
            P sl, it;
            sl = line.first; it = line.second;
            ll dx, dy;
            dx = sl.first; dy = sl.second;
            ll s, t;
            s = it.first; t = it.second;
            if(t == 0 && dx == 0 && x[i] == s) (lines[j].second)++;
            else if(t == 0 && dy == 0 && y[i] == s) (lines[j].second)++;
            else if(t != 0 && dx * t * y[i] == dy * t * x[i] + dx * s) (lines[j].second)++;
    }
    int ans = 0;
    rep(j, sz) if(lines[j].second >= k) ans++;

    cout << ans << endl;

}