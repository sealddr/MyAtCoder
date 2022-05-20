#include<bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int k;
    cin>>k;
    int a,b;
    cin >> a>>b;
    for(int i = a; i <= b; i++){
        if(i % k == 0) {
            cout << "OK" << endl;
            return 0;
        }
    }
    cout << "NG" << endl;
}