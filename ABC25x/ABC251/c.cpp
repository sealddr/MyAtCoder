#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

template <typename T>
bool chmax(T& a, const T& b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    unordered_map<string, bool> mpi;
    int mxt = -1;
    int mxi;
    rep(i, n) {
        string s;
        int t;
        cin >> s >> t;
        if(mpi.count(s)) continue;
        mpi[s]=true;
        if(mxt < t){
                mxt = t;
                mxi = i + 1;                
         }
    }
    cout << mxi << endl;
}