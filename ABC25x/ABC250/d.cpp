#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll MAXQ = 1000000;
ll arr[1000005];
ll cnt[1000005];
void eratosthenes() {
    for(int i = 0; i < MAXQ; i++) {
        arr[i] = 1;
    }
    for(int i = 2; i < sqrt(MAXQ); i++) {
        if(arr[i]) {
            for(int j = 0; i * (j + 2) < MAXQ; j++) {
                arr[i * (j + 2)] = 0;
            }
        }
    }
    cnt[2] = arr[2];
    for(int i = 2; i < MAXQ; i++)
        cnt[i + 1] += cnt[i] + arr[i + 1];
}

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    eratosthenes();
    for(ll q = 2; q < MAXQ && 1 < n / (q * q * q); q++) {
        if(!arr[q]) continue;
        ll p = n / (q * q * q);
        if(p >= q) p = q - 1;
        ans += cnt[p];
    }
    cout << ans << endl;
}
