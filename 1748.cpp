#include <iostream>
using namespace std;

int main() {
  int N, sum = 0;
  int t = 10;
  int cnt = 1, i = 1;
  cin >> N;

  while(i <= N){
    if(t > i){
      i++;
      sum += cnt;
    }
    else{
      t *= 10;
      cnt += 1;
    }
  }
  cout << sum << '\n';
  return 0;
}


