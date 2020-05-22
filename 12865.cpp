#include <iostream>
#include <algorithm>
using namespace std;

int W[101];
int V[101];
int D[100001] = { 0 };
int N, K;

int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> W[i] >> V[i];
    }
    for(int i = 1; i <= N; i++){
        for(int j = K; j >= 1; j--){
            if(j >= W[i]){
                D[j] = max(D[j], D[j-W[i]] + V[i]);
            }
        }
    }
    cout << D[K] << '\n';
    return 0;
}
