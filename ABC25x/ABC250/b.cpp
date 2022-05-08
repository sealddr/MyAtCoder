#include<bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n,a,b;
    cin >>n>>a>>b;
    rep(j,n*a){
        rep(i,n*b){
         printf("%c",(j/a+i/b)%2==0 ? '.' : '#');
        }
        cout << endl;
    }
    return 0;
}