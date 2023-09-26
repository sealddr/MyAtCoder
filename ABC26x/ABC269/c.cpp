#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> validdigit;

void dfs(ll x, int depth){
    if(depth >= validdigit.size()) {
        cout << x << endl;
        return;
    }
    ll adder = (1LL << validdigit[depth]);
    ++depth;
    dfs(x, depth);
    dfs(x + adder, depth);
}

int main(){
    ll n;
    cin >> n;
    int digit = 0;
    while(n){
        if(n&1LL) validdigit.push_back(digit);
        ++digit;
        n >>= 1;
    }
    reverse(validdigit.begin(),validdigit.end());
    dfs(0, 0);
    return 0;   
}