#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    ll rem = n % b;  
    if(n >= b)cout << (a * (b-1)) / b << endl;
    else cout << (a * rem) / b << endl;
}