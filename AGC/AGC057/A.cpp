#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

bool pred(int x){
    
}

int f(int x) {
    int ok = x;
    int ng = 0;
    while(abs(ok - ng) > 1) {
        int mid = abs(ok + ng) / 2;
        if(pred(mid)) ng = mid;
        else ok = mid;
    }
    return ok;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) {
        int l, r;
        cin >> l >> r;
        cout << f(r) - f(l) << endl;
    }
    return 0;
}