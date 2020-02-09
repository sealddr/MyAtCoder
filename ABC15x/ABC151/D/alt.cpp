#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int INF = 1000000000;
int h, w;
vector<string> maze(22);

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};

int bfs(int si, int sj) {
  vector<vector<int>> d(h, vector<int>(w, INF));
  queue<P> que;
  que.push(P(si, sj));
  d[si][sj] = 0;
  while(que.size()) {
    P p = que.front();
    que.pop();
    rep(dir, 4) {
      int ni = p.first + di[dir];
      int nj = p.second + dj[dir];
      if(0 <= ni && ni < h && 0 <= nj && nj < w
         && maze[ni][nj] == '.' && d[ni][nj] == INF) {
        que.push(P(ni, nj));
        d[ni][nj] = d[p.first][p.second] + 1;
      }
    }
  }
  int res = 0;
  rep(i, h) rep(j, w) if(maze[i][j] == '.') res =
    max(res, d[i][j]);
  return res;
}

int main(void) {
  cin >> h >> w;
  rep(i, h) cin >> maze[i];
  int ans = 0;
  rep(i, h) rep(j, w) {
    if(maze[i][j] == '.') {
      ans = max(ans, bfs(i, j));
    }
  }
  cout << ans << endl;
  return 0;
}