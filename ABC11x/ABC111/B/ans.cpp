#include <iostream>
#include <cmath>
using namespace std;
int main(void){
  int N;
  cin >> N;
  int ans = N;
  if(0 != N % 111){
    ans = ((N / 111) + 1) * 111;
  }
  cout << ans << endl;
  return 0;
}

