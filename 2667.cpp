#include<iostream>
#include<cstdio>
using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visit[26][26] = { 0 };
bool apart[26][26];
int ans[26*26];
int cnt = 0;
int n_x, n_y;
int N;

int isInside(int x, int y){
	if( x >= 0 && y >= 0 && x < N && y < N){
		return 0;
	}
	else{
		return -1;
	}
}

int DFS(int x, int y){
	visit[x][y] = true;
	ans[cnt]++;//배열에 단지 개수 저장
	for(int k = 0; k < 4; k++){
		n_x = x + dir[k][0];
		n_y = y + dir[k][1];
		if(isInside(n_x, n_y) == 0 && visit[n_x][n_y] == false){
			if(apart[n_x][n_y] == true){
				DFS(n_x, n_y);
			}
		}
	}
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%1d", &apart[i][j]);//한자리씩 받기
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(apart[i][j] == 1 && visit[i][j] == false){
				DFS(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	for(int i = 0; i < cnt-1; i++){
		for(int j = 0; j < cnt-1; j++){
			if(ans[j] > ans[j+1]){
				int t = ans[j];
				ans[j] = ans[j+1];
				ans[j+1] = t;
			}
		}
	}

	for(int i = 0; i < cnt; i++){
		cout << ans[i] << '\n';
	}
	return 0;
}
