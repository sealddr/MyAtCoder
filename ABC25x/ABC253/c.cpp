#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    map<int, int> mp;
    while (q--){
        int code;
        cin >> code;
        if(code == 1) {
            int x;
            cin >> x;
            mp[x]++;
        }else if(code == 2){
            int x, c;
            cin >> x >> c;
            if(mp[x]-c <= 0) mp.erase(x);
            else mp[x] -= c;
        }else{
            auto l = mp.begin();
            auto r = mp.rbegin();
            cout << r -> first - l -> first << endl;
        }
    }
}