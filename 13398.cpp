#include<iostream>
#include<algorithm>
using namespace std;

int n;
int A[100001] = { 0 };
int D[100001][2] = { 0 };

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    //1. 값 한개 제거
    //2. 연속되는 수 중 가장 큰 것
    D[0][0] = A[0];
    D[0][1] = A[0];
    for(int i = 1; i < n; i++){
        D[i][0] = max(D[i-1][1], D[i-1][0] + A[i]);
        D[i][1] = max(D[i-1][1] + A[i], A[i]);
    }
    int ans = D[0][0];
    for(int i = 0; i < n; i++){
        ans = max(ans, D[i][0]);
        ans = max(ans, D[i][1]);
    }
    cout << ans << '\n';
    return 0;
}
