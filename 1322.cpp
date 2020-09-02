#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long long answer = 0;
long long X, K;
int i = 0;
int cnt = 0, mv = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> X >> K;
    while((K >> i++) != 0);
    i -= 1;
    while(cnt < i){
        //X의 비트가 0일때를 구하기 위함
        while(((X >> mv++) & 1) != 0);
        //K를 이진수로 바꿨을 때 해당 비트가 1일 때 answer값에 더해줌
        if(((K >> cnt)&1) != 0){
            answer += pow(2, mv-1);
        }
        cnt++;
    }
    cout << answer <<'\n';
    return 0;
}