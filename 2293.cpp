#include<cstdio>
#include<string.h>
int coin[101];
int DP[10001] = { 0 };//값 저장
int n, k;

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d",&coin[i]);
	}
	DP[0] = 1;//DP에 k값을 점차 늘려가면서 얼마나 가능한지 구함, 최소 1
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			if(j >= coin[i]){//현재 코인보다 클때
				DP[j] += DP[j - coin[i]];
				//현재DP는 현재가격 - 코인
			}
		}
	}
	printf("%d", DP[k]);
	return 0;
}


