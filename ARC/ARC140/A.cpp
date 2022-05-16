#include<bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> divisor(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

bool can(string s, int n, int k, int div){
    vector<vector<int>> cnts(div, vector<int>(26));
    rep(i, n) cnts[i % div][s[i] - 'a']++;
    int tot = 0;
    rep(i, div){
        vector<int> cnt = cnts[i % div];
        sort(cnt.begin(),cnt.end());
        rep(j, 25) tot += cnt[j];
    }
    if (k >= tot) return true;
    return false;
}

int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> divs = divisor(n);
    int dn = divs.size();
    rep(i,dn){
        if(can(s, n, k, divs[i])) {
            cout << divs[i] << endl;
            return 0;
        }
    }

}