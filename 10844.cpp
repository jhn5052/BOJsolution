#include<iostream>
using namespace std;
#define DV 1000000000
long dp[101][11];
int N;

int main(){
	long result = 0;
	cin >> N;
	for(int i = 1; i <= 9; i++){
		dp[1][i] = 1;//길이 하나 차이날때, 기본설정값
	}
	for(int i = 2; i <= N; i++){
		dp[i][0] = dp[i-1][1];//끝자리가 0일때 +1한것밖에 안됨
		for(int j = 0; j <= 9; j++){
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
			dp[i][j] = dp[i][j] % DV;
		}
	}
	for(int i = 0; i <= 9; i++){
		result += dp[N][i];
	}
	cout << result % DV;
	return 0;
}
