#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int memo[100100];

int chmin(int a, int b){
    if(a < b) return a; else return b;
}

int f(int n) {
    if(n == 0) return 0;
    if(memo[n]) return memo[n];
    int res = 100001;

    res = chmin (res, f(n - 1) + 1);

    int k = 6;
    while (k <= n){
        res = chmin (res, f(n - k) + 1);
        k *= 6;
    }

    k = 9;
    while (k <= n){
        res = chmin (res, f(n - k) + 1);
        k *= 9;
    }
    return memo[n] = res;
}

int main(){
    int n;
    cin >> n;
    cout << f(n) << endl;
 }
