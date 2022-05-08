#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    vector<bool> pairedR(n), pairedB(n);
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, n) cin >> c[i] >> d[i];

    for(int x = 0; x < 2 * n; x++) {
        rep(j, n) {            
            if(c[j] != x) continue;
            if(pairedB[j]) continue;
            int maxb = -1;
            int maxi;
            rep(i, n) {
                if(pairedR[i]) continue;
                if(a[i] >= x) continue;
                if(b[i] >= d[j]) continue;
                if(b[i] > maxb) {
                    maxb = b[i];
                    maxi = i;
                }
            }
            if(maxb == -1) continue;
            pairedR[maxi] = true;
            pairedB[j] = true;
        }
    }
    int ans = 0;
    rep(i, n) if(pairedR[i]) ans++;
    cout << ans << endl;
}