#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    ll n,p;
    cin >> n >> p;
    vector<vector<ll>> dpCG(n + 1, vector<ll>(n + 5));
    vector<vector<ll>> dpIF(n + 1, vector<ll>(n + 5));
    for(int k = 1; k <= n; k++) for (int i = 0; i < n; i++){
        dpCG[k][i] = 0LL; dpIF[k][i] = 0LL;
    }
    dpCG[1][3] = 1LL; dpCG[1][4] = 0LL;
    dpIF[1][3] = 0LL; dpIF[1][4] = 1LL;

    for(int k = 2; k <= n; k++) for (int i = 3; i < n + 3; i++){
        dpCG[k][i] = (dpCG[k][i] + dpCG[k - 1][i]) % p;
        dpCG[k][i] = (dpCG[k][i] + 3 * dpCG[k - 1][i - 1]) % p;
        dpCG[k][i] = (dpCG[k][i] + dpIF[k - 1][i]) % p;

        dpIF[k][i] = (dpIF[k][i] + dpIF[k - 1][i - 1]) % p;
        dpIF[k][i] = (dpIF[k][i] + 2 * dpCG[k - 1][i - 2]) % p;
    }


    for (int i = 4; i < n + 3; i++) cout << dpCG[n][i] << " ";
    cout << endl;
}