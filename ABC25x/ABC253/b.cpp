#include<bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int h,w;
    cin >> h >> w;
    string s[h];
    rep(i,h) cin >> s[i];
    int x0, y0, x1, y1;
    rep(i, h) rep(j, w){
        if(s[i][j] == 'o') {
            x0 = j;
            y0 = i;
        }
    }
    rep(i, h) rep(j, w){
        if(s[i][j] == 'o') {
            if(i == y0 && j == x0) continue;
            x1 = j;
            y1 = i;
        }
    }
    cout << abs(x1-x0) + abs(y1-y0) << endl;
}