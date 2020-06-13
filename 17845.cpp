#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int Time[10001];
int Value[10001];
int dp[10001] = { 0 };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for(int i = 1; i <= K; i++){
        cin >> Value[i] >> Time[i];
    }
    for(int i = 1; i <= K; i++){
        for(int j = N; j > 0; j--){
            if(j >= Time[i]){
                dp[j] = max(dp[j], dp[j-Time[i]]+Value[i]);
            }
        }
    }
    cout << dp[N] << '\n';
    return 0;
}
