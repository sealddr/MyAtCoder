#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MAXN 200005

vector<vector<int>> to(MAXN);
vector<bool> dfsVisited(MAXN);
vector<bool> bfsVisited(MAXN);

void dfs(int now) {
    dfsVisited[now] = true;
    for(auto x : to[now]) {
        if(dfsVisited[x]) continue;
        printf("%d %d\n", now + 1, x + 1);
        dfs(x);
    }
}

void bfs(int root) {
    queue<int> q;
    bfsVisited[root] = true;
    q.push(root);
    while(q.size()) {
        int p = q.front();
        q.pop();
        for(auto x : to[p]) {
            if(bfsVisited[x]) continue;
            printf("%d %d\n", p + 1, x + 1);
            bfsVisited[x] = true;
            q.push(x);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    to.resize(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        to[u].push_back(v);
        to[v].push_back(u);
    }

    dfsVisited.resize(n);
    dfs(0);

    bfsVisited.resize(n);
    bfs(0);
}