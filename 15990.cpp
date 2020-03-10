#include<iostream>
using namespace std;
int T, N;
long long D[100001][4] = { 0 };

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        D[0][0] = 0;
        D[1][1] = 1; // 1
        D[1][2] = 0;
        D[1][3] = 0;

        D[2][1] = 0;
        D[2][2] = 1; // 2
        D[2][3] = 0;

        D[3][1] = 1;
        D[3][2] = 1;
        D[3][3] = 1; // 1+2, 2+1, 3
        for(int i = 4; i <= N; i++){
            D[i][1] = (D[i-1][2] + D[i-1][3]) % 1000000009;
            D[i][2] = (D[i-2][1] + D[i-2][3]) % 1000000009;
            D[i][3] = (D[i-3][1] + D[i-3][2]) % 1000000009;
        }
        cout << (D[N][1] + D[N][2] + D[N][3]) % 1000000009 << '\n';
    }
    return 0;
}