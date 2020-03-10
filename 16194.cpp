#include<iostream>
#include<algorithm>
using namespace std;

int N;
int P[10001] = { 0 };
int D[10001] = { 0 };
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> P[i];
    }
    D[0] = 0;
    D[1] = P[1];
    D[2] = min(D[1] + D[1], P[2]);
    int ans;
    for(int i = 3; i <= N; i++){
        ans = P[i];
        for(int j = 1; j <= i-1; j++){
            ans = min(ans, D[i-j] + P[j]);
        }
        D[i] = ans;
    }
    cout << D[N] << '\n';
    return 0;
}

