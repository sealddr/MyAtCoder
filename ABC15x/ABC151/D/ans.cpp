#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;

typedef pair<int, int> P;
int h, w;
vector<string> maze(30);
int ans = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int sx, int sy) {
  queue<P> que;
  vector<vector<int>> dist(h, vector<int>(w, -1));
  que.push(P(sx, sy));
  dist[sx][sy] = 0;
  while(que.size()) {
    P p = que.front();
    que.pop();
    rep(k, 4) {
      int nx = p.first + dx[k], ny = p.second + dy[k];
      if(0 <= nx && nx < h && 0 <= ny && ny < w
         && maze[nx][ny] != '#' && dist[nx][ny] == -1) {
        que.push(P(nx, ny));
        dist[nx][ny] = dist[p.first][p.second] + 1;
      }
    }
  }
  rep(i, h) rep(j, w) if(dist[i][j] > ans) ans = dist[i][j];
}

int main(void) {
  cin >> h >> w;
  rep(i, h) cin >> maze[i];
  rep(i, h) {
    rep(j, w) {
      if(maze[i][j] == '.')
        bfs(i, j);
    }
  }
  cout << ans << endl;
  return 0;
}