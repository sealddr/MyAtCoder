#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
  int N;
  cin >> N;
  vector<int> X(N);
  vector<int> Y(N);
  for(int i = 0; i < N; i++){
    cin >> X[i] >> Y[i];

  }
  int r = abs(X[0] + Y[0]) % 2;
  for(int i = 1; i < N; i++){
    if(r != (abs(X[i] + Y[i]) % 2)){
      cout << -1 << endl;
      return 0;

    }
  }
  int m = 20 - r;
  vector<int> d(m);
  
  for(int i = 0; i < N; i++){
    int cnt = 0;
    if(0 < X[i]){
      for(int x = 0; x < X[i] && cnt < m; x++, cnt++){
        cout << 'R';

      }
    }else{
      for(int x = 0; x > X[i] && cnt < m; x--, cnt++){
        cout << 'L';

      }

    }
    if(0 < Y[i]){
      for(int y = 0; y < Y[i] && cnt < m; y++, cnt++){
        cout << 'U';

      }
    }else{
      for(int y = 0; y > Y[i] && cnt < m; y--, cnt++){
      cout << 'D';

      }

    }
    for(; cnt < m; cnt+=2){
      cout << "DU";

    }
    cout << endl;
  }
  

  return 0;
}