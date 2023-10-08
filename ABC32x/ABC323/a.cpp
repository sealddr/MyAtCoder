#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

const int N = 16;

int main(){
    string s;
    cin >> s;
    bool allzero = true;
    rep(i, N){
        i++;
        if(s[i] == '1'){
            allzero = false;
            break;
        }
    }
    puts(allzero ? "Yes" : "No");
    return 0;
}