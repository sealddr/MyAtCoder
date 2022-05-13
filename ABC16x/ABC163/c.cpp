#include<bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n;
    cin >> n;
    vector<int> cnt(n);
    rep(i, n-1) {
        int x;
        cin >> x;
        cnt[x - 1]++;
    }
    rep(i,n) cout << cnt[i] << endl;
}