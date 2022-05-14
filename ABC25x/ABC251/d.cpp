#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
int main() {
    int w;
    cin >> w;
    vector<int> a;
    for(int i = 1; i<100; i++){
        a.push_back(i);
        a.push_back(100*i);
        a.push_back(10000*i);
    }
    a.push_back(1000000);
    int n = a.size();
    cout << n << endl;
    rep(i,n){
        cout << a[i] << " ";
    }
    cout << endl;
}