#include<iostream>
#include<algorithm>
using namespace std;

int N;
int A[1001] = { 0 };
int D[1001] = { 0 };

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    for(int i = 0; i < N; i++){
        D[i] = 1;
        for(int j = 0; j < i; j++){
            if(A[i] < A[j]){
                if(D[i] < D[j] + 1){
                    D[i] = D[j] + 1;
                }
            }
        }
    }

    int M = D[0];
    for(int i = 1; i < N; i++){
        M = max(M, D[i]);
    }
    cout << M;
    return 0;
}
