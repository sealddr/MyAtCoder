#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)

 ll dp[3005][3005][2];

int main(){
    ll n, p;
    cin >> n >> p;
    rep(i, n) rep(j, n) rep(k, 2) dp[i][j][k] = 0LL;
    dp[2][1][0] = 1LL; dp[3][1][1] = 1LL;
    for(int i = 2; i < n + 2; i++) for (int j = 2; j < n + 1; j++){
        dp[i][j][0] = (dp[i][j][0] + dp[i][j-1][0])            % p;
        dp[i][j][0] = (dp[i][j][0] + 3 * dp[i - 1][j - 1][0])  % p;
        dp[i][j][0] = (dp[i][j][0] + dp[i][j-1][1])            % p;
        dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j - 1][1])      % p;
        dp[i][j][1] = (dp[i][j][1] + 2 * dp[i - 2][j - 1][0])  % p;
    }
    for (int i = 3; i < n + 2; i++) cout << dp[i][n][0] << " ";
    cout << endl;
    return 0;
}