#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

// 文字列中の'o'個数をカウントする関数
int countwins(string s){
    int wins = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'o'){
            wins++;
        }
    }
    return wins;
}

int main(){
    int n;
    cin >> n;
    using MatchResult = pair<int, int>;
    vector<MatchResult> match_results;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int wins;
        wins =countwins(s);
        match_results.push_back(make_pair(wins, n - i));
    }

    sort(all(match_results), greater<MatchResult>());
    
    rep(i, n) cout << n + 1 - match_results[i].second << endl;
}