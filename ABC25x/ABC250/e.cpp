#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#define MAXN 200005

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    unordered_map<int, int> idxamp, idxbmp;
    rep(i, n) if(idxamp[a[i]] == 0) idxamp[a[i]] = i + 1;
    rep(i, n) if(idxbmp[b[i]] == 0) idxbmp[b[i]] = i + 1;

    int memo[n][2];
    memo[0][0] = memo[0][1] = 0;
    for(int i = 1; i <= n; i++) {
        if(idxbmp[a[i - 1]] == 0)
            memo[i][0] = MAXN;
        else
            memo[i][0] =
              max(memo[i - 1][0], idxbmp[a[i - 1]]);
    }
    for(int i = 1; i <= n; i++) {
        if(idxamp[b[i - 1]] == 0)
            memo[i][1] = MAXN;
        else
            memo[i][1] =
              max(memo[i - 1][1], idxamp[b[i - 1]]);
    }

    int q;
    cin >> q;
    rep(k, q) {
        int x, y;
        cin >> x >> y;
        printf("%s\n", memo[x][0] <= y && memo[y][1] <= x
                         ? "Yes"
                         : "No");
    }
    return 0;
}