#include<bits/stdc++.h>

using namespace std;

int main() {
    int s, w;
    cin >> s >> w;
    if(s <= w) {
        cout << "unsafe" << endl;
        return 0;
    }
    cout << "safe" << endl;
    return 0;
}