#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int cnt;
int arr[5001];
int dp[5001][5001];

int Solve(int L, int R){
    //끝나는 조건
    if(L > R){
        return 0;
    }

    int &ans = dp[L][R];
    if(ans != -1){
        return ans;
    }
    
    //같을때 앞 뒤로 하나씩 이동
    if(arr[L] == arr[R]){
        ans = Solve(L+1, R-1);
    }
    else{ //같지 않을 때
        //앞에 추가, 뒤에 추가
        ans = min(Solve(L, R - 1) + 1, Solve(L + 1, R) + 1);
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));
    cnt = Solve(0, N-1);
    cout << cnt << '\n';
    return 0;
}
