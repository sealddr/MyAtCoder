#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> pointAllocation = vector<int>(m, 0);
    rep(i, m){
        cin >> pointAllocation[i];
    }

    vector<vector<int>> anserStatus = vector<vector<int>>(n, vector<int>(m, 0));
    rep(i, n){
        string s;
        cin >> s;
        rep(j, m){
            if(s[j] == 'o'){
                anserStatus[i][j] = 1;
            }
        }
    }

    int topId;
    int topScore = 0;
    vector<int> totalScore = vector<int>(n, 0);
    rep(i, n){
        int score = i;
        rep(j, m){
            if(anserStatus[i][j] == 1){
                score += pointAllocation[j];
            }
        }
        totalScore[i] = score;
        if(score > topScore){
            topScore = score;
            topId = i;
        }
    }

    vector<int> anser = vector<int>(n, 0);
    rep(i, n){
        while(totalScore[i] < topScore){
            // pointAllocationのうち最大のものを探す
            int maxId;
            int maxScore = 0;
            rep(j, m){
                if(anserStatus[i][j] == 1) continue;
                if(pointAllocation[j] > maxScore){
                    maxScore = pointAllocation[j];
                    maxId = j;
                }
            }
            anserStatus[i][maxId] = 1;
            totalScore[i] += maxScore;
            anser[i]++;
        }
    }

    rep(i,n) cout << anser[i] << endl;
}