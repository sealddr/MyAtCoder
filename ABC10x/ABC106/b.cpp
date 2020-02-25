#include <iostream>
using namespace std;
int main() {
  int N;
  cin >> N;
  int cnt = 0;
  if(N >= 105) cnt++;
  if(N >= 135) cnt++;
  if(N >= 165) cnt++;
  if(N >= 195) cnt++;
  if(N >= 189) cnt++;
  cout << cnt << endl;
  return 0;
}