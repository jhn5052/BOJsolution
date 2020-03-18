#include <iostream>
using namespace std;
int gcd(int a, int b){
  while(b!=0){
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int lcm(int a, int b){
  return (a*b)/gcd(a,b);
}

int main() {
  int T, M, N, x, y;
  cin >> T;
  for(int tc = 0; tc < T; tc++){
    cin >> M >> N >> x >> y;
    int cnt = x % (M + 1);
    int ny = x;
    int end_case = lcm(M, N);
    bool flag = false;

    while(cnt < end_case){
      int tmp = ny % N;
      if(tmp == 0){
        tmp = N;
      }
      else{
        tmp = ny % N;
      }

      if(tmp == y){
        flag = true;
        cout << cnt << '\n';
        break;
      }
      ny = tmp + M;
      cnt += M;
    }
    if(flag == false){
      cout << -1 << '\n';
    }

  }
  return 0;
}
