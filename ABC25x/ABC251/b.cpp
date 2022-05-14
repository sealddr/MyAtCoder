#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    set<int> s;
    rep(i, n) if(a[i] <= w) s.insert(a[i]);
    rep(i, n) rep(j, i) if(a[i] + a[j] <= w)
      s.insert(a[i] + a[j]);

    rep(i, n) rep(j, i)
      rep(k, j) if(a[i] + a[j] + a[k] <= w)
        s.insert(a[i] + a[j] + a[k]);
    int ans = s.size();
    cout << ans << endl;
}