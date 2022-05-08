#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> pos(n + 1), x(n + 1);
    rep(i, n + 1) pos[i] = i;
    rep(i, n + 1) x[i] = i;

    rep(j, q) {
        int q;
        cin >> q;
        int tempx, temppos;
        if(pos[q] == n) {
            temppos = pos[q];
            tempx = x[pos[q]];
            pos[q]--;
            pos[x[temppos - 1]]++;
            x[temppos] = x[temppos - 1];
            x[temppos - 1] = tempx;
        } else {
            temppos = pos[q];
            tempx = x[pos[q]];
            pos[q]++;
            pos[x[temppos + 1]]--;
            x[temppos] = x[temppos + 1];
            x[temppos + 1] = tempx;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}