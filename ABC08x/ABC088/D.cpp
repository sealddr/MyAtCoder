#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (n); ++i)

const int MAXH = 60;
const int MAXW = 60;

vector<string> maze(MAXH);
vector<vector<int>> d(MAXH, vector<int>(MAXW));

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void bfs(int h,int w) {
    queue<P> q;
    for (int j = 0; j <= h+1; j++){
        for (int i = 0; i<= w+1; i++){
            d[j][i] = -1;
        }
    }
    d[1][1] = 1;
    q.push(P(1,1));
    while (q.size() > 0){
        P p = q.front(); q.pop();

        if(p.first == w && p.second == h) break;
        rep(dr,4){
            int nextx = p.first + dx[dr], nexty = p.second + dy[dr];
            if(maze[nexty][nextx] != '#' && d[nexty][nextx] == -1){
                q.push(P(nextx, nexty));
                d[nexty][nextx] = d[p.second][p.first] + 1;
            }
        }
    }
    return;
}

int main(){
    int h, w;
    cin >> h >> w;
    for(int j = 1; j <= h; j++){
        string s;
        cin >> s;
        maze[j] = '#' + s + "#";
    }

    string wallLine = "";
    rep(i,w + 2) {     
        wallLine += '#';
    }   
    maze[0] = wallLine;
    maze[h + 1] = wallLine;
   
    bfs(h, w);    

    if (d[h][w] == -1) {cout << -1 << endl;return 0;}

    int cntWalls = 0;
    for(int j = 1; j <= h; j++) for (int i = 1; i <= w; i++) if(maze[j][i] == '#') cntWalls++;
    int ans = (h * w - cntWalls - d[h][w]);
    cout << ans << endl;
}

