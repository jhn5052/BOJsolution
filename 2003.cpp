#include<iostream>
using namespace std;

long long N, M, sum;
int L, R, cnt;
int A[10001] = { 0 };

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    L = 0;
    R = 0;
    cnt = 0;
    sum = 0;
    while(1){
        if(L > R || R > N){
            break;
        }
        if(sum >= M){
            if(sum == M){
                cnt += 1;
            }
            sum -= A[L];
            L++;
        }
        else{
            if(R == N){
                break;
            }
            sum += A[R];
            R++;
        }
    }

    cout << cnt << '\n';
    return 0;
}
