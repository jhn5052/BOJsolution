#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 987654321

int N, M;
int arr[102];
int dp[101][51];
bool visit[101];//필요없을수도

int DP(){
	
	return DP[N][M];
}

int main(){
	cin >> N >> M;
	memset(dp, -INF, sizeof(dp));//모든 수가 -32768일때 대비하여 제일 작게
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}

