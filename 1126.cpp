#include<cstring>
#include<cstdio>
#define INF 987654321
#define MAX 500000

int D[51][250001];
int arr[51] = {0};
int N;

int max(int a, int b){
	return a > b ? a : b;
}

int DFS(int num, int dif){
	if(dif > 250000){
		return -INF;
		//이미 차를 넘어섰을 때
	}
	if(num == N){//끝까지 갔을때
		if(dif == 0){
			return 0;
		}
		else{
			return -INF;//탑높이의 최댓값이 되게
		}
	}
	if(D[num][dif] != -1){
		return D[num][dif];//값이 바꼈다는 뜻
	}
	D[num][dif] = -INF;
	//블록을 아무곳에도 놓지 않을때
	D[num][dif] = max(D[num][dif], DFS(num+1, dif));//재귀로 계속 들어갈 수 있다
	
	//블록을 큰쪽에 놓을때
	D[num][dif] = max(D[num][dif], DFS(num+1, dif + arr[num]));

	//블록을 작은쪽에 놓을 때
	//블록이 차보다 큰경우
	if(arr[num] > dif){
		D[num][dif] = max(D[num][dif], dif + DFS(num+1, arr[num] - dif));
	}
	//블록이 차보다 작은경우
	else if(arr[num] <= dif){
		D[num][dif] = max(D[num][dif], arr[num] + DFS(num+1, dif - arr[num]));
	}
	return D[num][dif];
}


int main(){
	scanf("%d", &N);
	memset(D, -1, sizeof(D));//메모이제이션
	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	int ans = DFS(0, 0);
	printf("%d", ans? ans : -1);
	return 0;
}
