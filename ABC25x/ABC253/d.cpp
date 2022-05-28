#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    if(a < b) return gcd(b, a);
    else return gcd(b , a % b);
}

int main(){
    ll n, a, b, ab;   
    cin >> n >> a >> b;
    ll s, sa, sb , sab;
    s = (1 + n) * n / 2;
    sa = (a + (n / a) * a) * ( n / a) / 2;
    sb = (b + (n / b) * b) * ( n / b) / 2;
    ab = a * b / gcd(a, b);
    sab = (ab + (n / ab) * ab) * ( n / ab) / 2;
    cout << s - (sa + sb - sab) << endl;
}