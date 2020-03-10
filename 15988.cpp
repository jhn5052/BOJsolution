#include<iostream>
using namespace std;
#define MAX 1000001

int T, n;
int D[MAX] = { 0 };

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        D[0] = 0;
        D[1] = 1; // 1
        D[2] = 2; //1+1, 2
        D[3] = 4; //1+1+1, 1+2, 2+1, 3
        for(int i = 4; i <= n; i++){
            D[i] = ((long long) D[i-1] + D[i-2] + D[i-3]) %  1000000009;
        }
        cout << D[n] << '\n';
    }
    return 0;
}
