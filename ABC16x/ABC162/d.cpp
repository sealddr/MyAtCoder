#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  int n;
  string s;
  cin >> n >> s;

  ll ans = 0;
  for(int i = 0; i < n - 1; i++) {    
    string sr = s.substr(0, i);
    string rsr (sr.rbegin(), sr.rend());
    ll cntrr = 0;
    ll cntrb = 0;
    for(int j = 0; j < rsr.length(); j++) {
      if(rsr[j] == 'R') cntrr++;
      if(rsr[j] == 'B') cntrb++;
    }

    string sb = s.substr(i + 1, n - i);
    ll cntlr = 0;
    ll cntlb = 0;
    for(int j = 0; j < sb.length(); j++) {
      if(sb[j] == 'R') cntlr++;
      if(sb[j] == 'B') cntlb++;
    }

    ll cntrrlb = 0;
    ll cntrblr = 0;
    for(int j = 0; j < rsr.length() && j < sb.length(); j++) {
      if(rsr[j] == 'R' && sb[j] == 'B') cntrrlb++;
      if(rsr[j] == 'B' && sb[j] == 'R') cntrblr++;
    }

    ans += cntrr * cntlb - cntrrlb;
    ans += cntrb * cntlr - cntrblr;
    cout << rsr << endl;
    cout << sb << endl;
  }
  cout << ans << endl;
}