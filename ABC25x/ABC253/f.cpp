#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> vl, vr, vx, vq;
    unordered_map<int, pair<int, int>> mp;
    while(q--){
        int code;
        cin >> code;
        if(code == 1){
            int l, r, x;
            cin >> l >> r >> x;
            vl.push_back(l);
            vr.push_back(r);
            vx.push_back(x);
            vq.push_back(q);
        }
        if(code == 2) {
            int i, x;
            cin >> i >> x;
            mp[i] = make_pair(q, x);
        }


    }

}