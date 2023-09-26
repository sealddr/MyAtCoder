#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

using namespace std;

int n, x;
vector<int> as;

bool isOK(int an){
    bool isok = false;

    sort(all(as));

    int sum = 0;
    for(int i = 1; i < n - 2 ; i++) sum += as[i];

    if(an < as[0]) sum += as[0];
    else if (as[n-2] < an) sum += as[n-2];
    else sum += an;    

    if(x <= sum) isok = true;
    return isok;
}

int main(){
    cin >> n >> x;
    as.resize(n - 1);
    rep(i, n - 1) cin >> as[i];

    int ok = 999;
    int ng = -1;
    while(abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;
        if(isOK(mid)) ok = mid;
        else ng = mid;
    }

    if(ok > 100) puts("-1");
    else printf("%d\n", ok);
    return 0;
}