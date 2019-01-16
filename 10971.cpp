#include<iostream>
#include<string.h>
using namespace std;
int N;// number of city
int arr[11][11] = { 0 };
int visit[11] = { 0 };
int M = 90000000;
int start;

void DFS(int i, int cnt, int sum){
	if(cnt == N && start == i){
		if(M > sum){
			M = sum;
		}
		return;
	}
	for(int j = 0; j < N; j++){
		if(arr[i][j] != 0){
			if(visit[i] == 0){
				visit[i] = 1;
				if(M >= (sum + arr[i][j])){
					DFS(j, cnt+1, sum + arr[i][j]);
				}
				visit[i] = 0;
			}
		}
	}
}
		

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){//i = 세로
		for(int j = 0; j < N; j++){//j = 가로
			//(i,j)로 갈때 비용
			cin >> arr[i][j];
		}
	}

	for(int i = 0; i < N; i++){
		start = i;//시작점
		DFS(i, 0, 0);//방문하는 점, 점 개수, 합
		memset(visit, 0, sizeof(visit));
	}
	cout << M << '\n';
	return 0;
}
