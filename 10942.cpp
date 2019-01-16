#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
bool dp[2001][2001];
int arr[2001] = { 0 };
int N;
void find(){
	//길이가1인애들 다 true
	for(int i = 1; i <= N; i++){
		dp[i][i] = true;
	}
	//길이가 2인 애들 판별
	for(int i = 1; i <= N; i++){
		if(arr[i] == arr[i+1]){
			dp[i][i+1] = true;
			dp[i+1][i] = true;
		}
	}
	//길이가 3이상
	for(int i = 2; i < N; i++){
		for(int j = 1; j <= N-i; j++){
			if(arr[j] == arr[j+i]){
				if(dp[j+1][j + i - 1]){
					dp[j][j+i] = true;
					dp[j+i][j] = true;
				}
			}
		}
	}
}

int main(){
	int M, S, E;//질문, 정수1, 정수2
	scanf("%d", &N);//자연수 개수
	for(int i = 1; i <= N; i++){
		scanf("%d", &arr[i]);
	}
	memset(dp,false,sizeof(dp));
	scanf("%d", &M);//질문 개수
	find();
	for(int i = 0; i < M; i++){
		scanf("%d %d", &S, &E);//양쪽 끝 수
		printf("%d\n", dp[S][E]);
	}
	return 0;
}


