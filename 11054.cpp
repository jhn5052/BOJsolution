#include<iostream>
#include<algorithm>
using namespace std;

int N;
int A[1001] = { 0 };
int D1[1001] = { 0 };
int D2[1001] = { 0 };

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    //1. 가장 긴 증가하는 수열
    for(int i = 0; i < N; i++){
        D1[i] = 1;
        for(int j = 0; j < i; j++){
            if(A[i] > A[j]){
                if(D1[i] < D1[j] + 1){
                    D1[i] = D1[j] + 1;
                }
            }
        }
    }

    //2. 가장 긴 감소하는 수열
    for(int i = N-1; i > -1; i--){
        D2[i] = 1;
        for(int j = N-1; j >= i; j--){
            if(A[i] > A[j]){
                if(D2[i] < D2[j] + 1){
                    D2[i] = D2[j] + 1;
                }
            }
        }
    }

    /* <print>
    for(int i = 0; i < N; i++){
        cout << D1[i] << ' ';
    }
    cout << '\n';
    for(int i = 0; i < N; i++){
        cout << D2[i] << ' ';
    }
    */
    //1 + 2
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans = (D1[i] + D2[i] -1) > ans ? (D1[i] + D2[i] -1) : ans;
    }
    cout << ans << '\n';
    return 0;
}
