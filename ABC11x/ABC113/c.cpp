#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

string sub(int x) {
  string res = "";
  rep(i, 6) {
    if(x > 0) {
      char c = '0' + (x % 10);
      res = c + res;
    } else {
      res = '0' + res;
    }
    x /= 10;
  }
  return res;
}

string prefid(int p) {
  return sub(p);
}

string cityid(int y) {
  return sub(y);
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<P> cities(m);
  map<int, P> cnums;
  rep(j, m) {
    int p, y;
    cin >> p >> y;
    cities[j] = make_pair(p, y);
    cnums[j] = cities[j];
  }
  sort(all(cities));
  int cnt = 0;
  int prevp = cities[0].first;
  map<P, string> ids;
  rep(j, m) {
    P c = cities[j];
    if(prevp == c.first)
      cnt++;
    else {
      cnt = 1;
      prevp = c.first;
    }
    ids[c] = prefid(cities[j].first) + cityid(cnt);
  }
  rep(j, m) { cout << ids[cnums[j]] << endl; }
  return 0;
}