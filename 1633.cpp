//최고의 팀만들기
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int N = 1;
int team[1001][2];
int dp[1001][16][16]; //총 사람수/백/흑
int w, b;

int main() {
	while (scanf("%d %d", &w, &b) != EOF) {
		team[N][0] = w;
		team[N][1] = b;
		N++;
	}
	
	for (int i = 1; i < N; i++) {//초기화
		dp[i][0][1] = team[i][1]; // 부분문제크기/백팀(0)/흑팀(1);
		dp[i][1][0] = team[i][0];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= 15; j++) {
			for (int k = 0; k <= 15; k++) {
				dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
				if (j >= 1) {
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + team[i][0]);
				}
				if (k >= 1) {
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + team[i][1]);
				}
			}

		}
	}
	cout << dp[N - 1][15][15];
	return 0;
}
