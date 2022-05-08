#include<bits/stdc++.h>

using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    int r,c;
    cin >> r >> c;
    int ans = 4;
    if(r==1) ans--;
    if(r==h) ans--;
    if(c==1) ans--;
    if(c==w) ans--;
    cout << ans << endl;
}