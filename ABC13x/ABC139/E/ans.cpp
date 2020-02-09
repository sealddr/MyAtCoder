#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main(void) {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n - 1));
  rep(i, n) rep(j, n - 1) cin >> a[i][j];
  rep(i, n) rep(j, n - 1)-- a[i][j];

  vector<int> opponent_idx(n, 0);
  vector<bool> chkbox(n);
  int minidx = 0;
  int day = 0;

  vector<int> target_players;
  vector<int> matched_players;
  while(minidx < n - 1) {
    chkbox.assign(n, false);
    ++day;

    if(day == 1) {
      rep(i, n) target_players.push_back(i);
    } else {
      target_players = matched_players;
      matched_players.clear();
    }

    rep(k, target_players.size()) {
      int i = target_players[k];
      if(chkbox[i]) continue;
      if(opponent_idx[i] == n - 1) continue;
      int j = a[i][opponent_idx[i]];
      if(chkbox[j]) continue;
      if(a[j][opponent_idx[j]] != i) continue;
      matched_players.push_back(i);
      matched_players.push_back(j);
      ++opponent_idx[i];
      chkbox[i] = true;
      ++opponent_idx[j];
      chkbox[j] = true;
    }

    bool ok = false;
    rep(i, n) ok = ok || chkbox[i];
    if(!ok) {
      cout << -1 << endl;
      return 0;
    }

    minidx = opponent_idx[0];
    rep(i, n) minidx = min(minidx, opponent_idx[i]);
  }
  cout << day << endl;
  return 0;
}