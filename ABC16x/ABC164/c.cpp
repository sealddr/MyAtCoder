#include<bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n;
    cin >>n;
    unordered_map<string,bool> mp;
    rep(i,n) {
        string s;
        cin >> s;
        mp[s]=true;
    }
    cout << mp.size() << endl; 
}