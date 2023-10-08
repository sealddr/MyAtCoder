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
        match_results.push_back(make_pair(wins, i + 1));
    }

    sort(all(match_results), [](const MatchResult& a, const MatchResult& b) {
        if (a.first != b.first) {
            return a.first > b.first;
        } else {
            return a.second < b.second;
        }
    });
       
    rep(i, n - 1) cout << match_results[i].second << " ";
    cout << match_results[n - 1].second << endl;
}