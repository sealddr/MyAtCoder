#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
using namespace std;

int arr[10];

ll dpow(int keta){
    ll ret = 1;
    rep(i, keta) ret *= 10;
    return ret;
}

int main(){
    int k;
    cin >> k;

    rep(i,10) arr[i] = i;
    vector<ll> as;
    for(int bm = 2; bm <(1 << 10); bm++){
        ll now = 0;
        int keta = 0;
        int i = 0;
        int wbm = bm;
        while(wbm){
            if(wbm % 2) {
                now += dpow(keta) * arr[i];
                keta++;
            }
            wbm /= 2;
            i++;
        }
        as.push_back(now);        
    }
    sort(all(as));
    cout << as[k - 1] << endl;
    return 0;

}