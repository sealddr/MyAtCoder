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
    unordered_map<string, int> mpi;
    vector<pair<int, int>> score(n);
    rep(i, n) score[i] = make_pair(-1, i + 1);
    int mx = -1;
    rep(i, n) {
        string s;
        int t;
        cin >> s >> t;
        if(mpi.count(s))
            continue;
        else {
            score[i].first = t;
            mpi[s] = i;
            chmax(mx, t);
        }
    }
    sort(score.begin(), score.end());
    rep(i, n) {
        if(mx == score[i].first) {
            cout << score[i].second << endl;
            return 0;
        }
    }
}