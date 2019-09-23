//2775 아파트
#include <iostream>
#include<string.h>
using namespace std;

int T;
int K, N; //K층 N호
int apart[15][15] = { 0 };
int main(){
    cin >> T;
    for(int tc=1; tc <= T; tc++){
        cin >> K >> N;
        memset(apart, 0 , sizeof(apart)); //0으로 초기화
        for(int i = 1; i <= N; i++){
            apart[0][i] = i; //0층 1호부터 N호까지 initialize
        }
        for(int i = 1; i <= K; i++){
            for(int j = 1; j <= N; j++){
                apart[i][j] = apart[i][j-1] + apart[i-1][j];
            }
        }
        cout << apart[K][N] << '\n';
    }
    return 0;
}