#include <bits/stdc++.h>

using namespace std;

int kyori(int tw, int s, int ti, int x) {
    return (x / (tw + ti)) * (tw * s)
           + min(tw, (x % (tw + ti))) * s;
}

int main() {
    int a, b, c, d, e, f, x;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    cin >> x;
    string ans = "Draw";
    int kT = kyori(a, b, c, x);
    int kA = kyori(d, e, f, x);
    if(kT > kA)
        ans = "Takahashi";
    else if(kT < kA)
        ans = "Aoki";
    cout << ans << endl;
}