#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
  int N;
  cin >> N;
  vector<int> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];

  }
  vector<int> D(100001, 0);
  for(int i = 0; i < N; i+=2){
    D[v[i]]++;

  }
  vector<int> U(100001, 0);
  for(int i = 1; i < N; i+=2){
    U[v[i]]++;

  }

  int D1 = 0, D2 = 0;
  int cntD1 = 0, cntD2 = 0;
  for(int i = 0; i < 100001; i++){
    if(cntD2 < D[i]){
      if(cntD1 < D[i]){
        D2 = D1;
        D1 = i;
        cntD2 = cntD1;
        cntD1 = D[i];

      }else{
        D2 = i;
        cntD2 = D[i];

      }
    }
  }

  int U1 = 0, U2 = 0;
  int cntU1 = 0, cntU2 = 0;
  for(int i = 0; i < 100001; i++){
    if(cntU2 < U[i]){
      if(cntU1 < U[i]){
        U2 = U1;
        U1 = i;
        cntU2 = cntU1;
        cntU1 = U[i];

      }else{
        U2 = i;
        cntU2 = U[i];

      }
    }
  }

  if(D1 != U1){
    cout << N - (cntD1 + cntU1) << endl;
    return 0;

  }if(D1 == U1){
    if(0 == cntD2 && 0 == cntU2){
      cout << cntU1 << endl;
      return 0;

    }
    if(0 == cntD2){
      cout << (N / 2 - cntU2) << endl;
      return 0;

    }
    if(0 == cntU2){
      cout << (N / 2 - cntD2) << endl;
      return 0;

    }
    if(cntD1 == cntD2 || cntU1 == cntU2){
      cout << N - (cntD1 + cntU1) << endl;
      return 0;

    }
    if(cntD2 <= cntU2){
      cout << (N - (cntD1 + cntU2)) << endl;
      return 0;

    }if(cntD2 > cntU2){
      cout << (N - (cntD2 + cntU1)) << endl;

    }
  }
  return 0;
}