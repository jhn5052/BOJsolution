#include<iostream>
#include<algorithm>
using namespace std;

int A[1001] = { 0 };
int D[1001] = { 0 };
int N;
int ans = 0;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    for(int i = 0; i < N; i++){
        D[i] = A[i];
        for(int j = 0; j <= i; j++){
            if(A[i] > A[j]){
                if(D[i] < D[j] + A[i]){
                    D[i] = D[j] + A[i];
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        ans = max(ans, D[i]);
    }

    cout << ans << '\n';
    return 0;
}
