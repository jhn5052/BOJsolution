#include<iostream>
using namespace std;

int N, K;
long long D[201][201] = { 0 };

int main(){
    cin >> N >> K;
    for(int i = 1; i <= K; i++){
        D[1][i] = i;
    }
    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= K; j++){
            if(j == 1){
                D[i][1] = 1;
                continue;
            }

            D[i][j] = (D[i][j-1] + D[i-1][j]) % 1000000000 ;
        }
    }
    cout << D[N][K] << '\n';
    return 0;
}
