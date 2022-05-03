#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

int main(void) {
   int n;
   ll h;
   cin >> n >> h;
   vector<ll> b(n);
   ll maxa = 0;
   rep(i,n){
       ll a;
       cin >> a >> b[i];
       maxa = max(maxa, a);
   }
   vector<ll> bb;
   rep(i,n) if(maxa < b[i]) bb.push_back(b[i]);

   ll ans = 0;
   sort(all(bb));
   reverse(all(bb));
   rep(i, bb.size()){
       h   -= bb[i];
       ans ++;
       if (h <= 0) {cout << ans << endl; return 0; }
   }
   cout << ans + (h + maxa -1) / maxa << endl;
}