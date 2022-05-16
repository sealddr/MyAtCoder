#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> cnts;
    int l, r;
    rep(i, n) {
        if(s[i - 1] == 'A' && s[i] == 'R'
           && s[i + 1] == 'C') {
            l = i - 1;
            r = i + 1;
            while(l - 1 >= 0 && s[l - 1] == 'A') l--;
            while(r + 1 >= 0 && s[r + 1] == 'C') r++;
            cnts.push_back(min(i - l, r - i));
        }
    }
    
    int sz = cnts.size();
    int tot = 0;
    rep(i, sz) tot += cnts[i];
    cout << min(tot, 2 * sz) << endl;
}