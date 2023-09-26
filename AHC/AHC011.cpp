#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

template <typename T>
bool chmax(T &a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

bool seen[11][11], finished[11][11];


bool conU(char c){
    return c == '2' || c == '3' || c == '6' || c == '7' || c == 'a' || c == 'b' || c == 'e' || c == 'f'; 
}

bool conD(char c){
    return c == '8' || c == '9' || c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f'; 
}

bool conL(char c){
    return c == '1' || c == '3' || c == '5' || c == '7' || c == '9' || c == 'b' || c == 'd' || c == 'f'; 
}

bool conR(char c){
    return c == '4' || c == '5' || c == '6' || c == '7' || c == 'c' || c == 'd' || c == 'e' || c == 'f'; 
}


int dfs(vector<string> s, int n, int i, int j, int pi, int pj){
    seen[i][j] = true;
    int res = 1;
    if(i > 0 && !finished[i - 1][j] && pi + 1 != i && conU(s[i][j]) && conD(s[i - 1][j])){
        if(seen[i - 1][j] && !finished[i - 1][j]) return -1;
        int resu = dfs(s, n, i - 1, j, i , j);
        if(resu < 0) return -1;
        res += resu;
    }
    if(j > 0 && !finished[i][j - 1] && pj + 1 != j && conL(s[i][j]) && conR(s[i][j - 1])){
        if(seen[i][j - 1] && !finished[i][j - 1]) return -1;
        int resl = dfs(s, n, i, j - 1, i , j);
        if(resl < 0) return -1;
        res += resl;
    }
    if(i + 1 < n && !finished[i + 1][j] && pi - 1 != i && conD(s[i][j]) && conU(s[i + 1][j])){
        if(seen[i + 1][j] && !finished[i + 1][j]) return -1;
        int resd = dfs(s, n, i + 1, j, i , j);
        if(resd < 0) return -1;
        res += resd;
    }
    if(j + 1 < n && !finished[i][j + 1] && pj - 1 != j && conR(s[i][j]) && conL(s[i][j + 1])){
        if(seen[i][j + 1] && !finished[i][j + 1]) return -1;
        int resr = dfs(s, n, i, j + 1, i , j);
        if(resr < 0) return -1;
        res += resr;
    }
    return res;
}

int eval(vector<string> s, int n){
    int res = 0;
    rep(i, n) rep(j, n) seen[i][j] = false;
    rep(i, n) rep(j, n) finished[i][j] = false;
    rep(i, n) rep(j, n){
        if(seen[i][j]) continue;
        chmax(res, dfs(s, n, i, j, -1, -1));
    }
    return res;
}

pair<int, string> solve(vector<string> s, int n, int t){
    string ops = "";
    string ans = "";
    int opt = 0;
    int axis = 0;
    const int MIN = 1;
    const int MAX = n - 1;
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<int> distr(MIN, MAX);

    int x = 0, y = 0;
    rep(i, n) rep(j, n) {
        if(s[i][j] == '0') {
            x = j;
            y = i;
        }
    }

    while(1) {
        int d = distr(eng);
        if(axis % 2) {
            int nx;
            if(x + d >= n) {
                nx = (x + d) % n;
                for(int j = x; j > nx; j--) {
                    swap(s[y][j], s[y][j-1]);
                    ops += 'L';
                    t--;
                    if(t < 0) break;
                    int now = eval(s, n);
                    if(opt < now) {
                        opt = now;
                        ans = ops;
                    }
                }
            }else{
                nx = x + d;
                for(int j = x; j < nx; j++) {
                    swap(s[y][j], s[y][j + 1]);
                    ops += 'R';
                    t--;
                    if(t < 0) break;
                    int now = eval(s, n);
                    if(opt < now) {
                        opt = now;
                        ans = ops;
                    }
                }                
            }
            x = nx;
        }else{
            int ny;
            if(y + d >= n){
                ny = (y + d) % n;
                for(int i = y; i > ny; i--) {
                    swap(s[i][x], s[i - 1][x]);
                    ops += 'U';
                    t--;
                    if(t < 0) break;
                    int now = eval(s, n);
                    if(opt < now) {
                        opt = now;
                        ans = ops;
                    }
                }
            }else{
                ny = y + d;
                for(int i = y; i < ny; i++) {
                    swap(s[i][x], s[i + 1][x]);
                    ops += 'D';
                    t--;
                    if(t < 0) break;
                    int now = eval(s, n);
                    if(opt < now) {
                        opt = now;
                        ans = ops;
                    }
                }
            }
            y = ny;
        }
       if(t < 0) break;
       axis++;
    }
    return make_pair(opt, ans);
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    int trial;
    switch (n)
    {
    case 6:
        trial = 1280;
        break;
    case 7:
        trial = 640;
        break;
    case 8:
        trial = 320;
        break;
    case 9:
        trial = 160;
        break;
    default:
        trial = 80;
        break;
    }
    string ans;
    int opt = 0;
    while(trial--){
        pair<int,string> now = solve(s, n, t);
        if(opt < now.first) {
            opt = now.first;
            ans = now.second;
        }
    }
    cout << ans << endl;
}