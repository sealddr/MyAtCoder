#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll balance = 100;
    ll x;
    cin >> x;
    int ans = 0;
    while(balance < x) {
        ans ++;
        ll d = balance / 100;
        balance += d;
    }
    cout << ans << endl;
}