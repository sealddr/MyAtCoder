#include <bits/stdc++.h>
using namespace std;

vector<int> eratosthenes(int n) {
    vector<int> parr(n + 1);
    parr[0] = 0;
    parr[1] = 0;
    for(int i = 2; i <= n; i++) parr[i] = 1;
    for(int i = 2; i * i <= n; i++) {
        if(!parr[i]) continue;
        for(int j = 0; i * (j + 2) <= n; j++)
            parr[i * (j + 2)] = 0;
    }
    return parr;
}