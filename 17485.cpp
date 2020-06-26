#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int N, M;
int map[1002][1002] = { 0 };
int dp[1002][1002][3] = { 0 };
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> map[i][j];
        }
    }
    

    
    for(int i = 0; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(i == 0){
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
                dp[i][j][2] = 0;
            }else{
                dp[i][j][0] = INT_MAX;
                dp[i][j][1] = INT_MAX;
                dp[i][j][2] = INT_MAX;
            }
        }
    }

    //점화식
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            //가장자리
            if(j == 1){
                dp[i][j][0] = min(dp[i-1][j][1]+map[i][j], dp[i-1][j+1][2]+map[i][j]);
                dp[i][j][1] = dp[i-1][j+1][2]+map[i][j];
            }
            else if(j == M){
                dp[i][j][1] = dp[i-1][j-1][0] + map[i][j];
                dp[i][j][2] = min(dp[i-1][j-1][0] + map[i][j], dp[i-1][j][1] + map[i][j]);
            }
            
            else{
                dp[i][j][0] = min(dp[i-1][j][1] + map[i][j], dp[i-1][j+1][2] + map[i][j]);
                dp[i][j][1] = min(dp[i-1][j-1][0] + map[i][j], dp[i-1][j+1][2] + map[i][j]);
                dp[i][j][2] = min(dp[i-1][j-1][0] + map[i][j], dp[i-1][j][1] + map[i][j]);
            }
        }
    }

    int ans = INT_MAX;
    for(int i = 1; i <= M; i++){
        ans = min(ans, min(dp[N][i][0], min(dp[N][i][1], dp[N][i][2])));
    }
    cout << ans << '\n';
    return 0;
}
