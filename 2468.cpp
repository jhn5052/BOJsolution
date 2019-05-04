//안전영역
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define MAX 101
int N;
int map[MAX][MAX];
int visit[MAX][MAX];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int ans = 0;


int DFS(int r, int c, int cnt) {
	visit[r][c] = cnt;
	for (int i = 0; i < 4; i++) {
		int nr = r + dir[i][0];
		int nc = c + dir[i][1];
		if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visit[nr][nc]) {//안잠긴 부분
			DFS(nr, nc, cnt);
		}
	}
	return 0;
}


int main() {
	int cnt = 0, h_max = 0; //지도 상에서 제일 높은 부분
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			h_max = max(map[i][j], h_max);
		}
	}

	for (int h = 0; h <= h_max; h++) {
		memset(visit, false, sizeof(visit));
		//강수량 이하인 노드 잠기게 표시
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] <= h) {
					visit[i][j] = 1;
				}
			}
		}

		/*
		//안전영역 개수 확인
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << visit[i][j] << ' ';
			}
			cout << endl;
		}

		cout << endl;
		*/
		cnt = 1;
		//안잠긴 애들부터 돌기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == 0) {
					DFS(i, j, cnt);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt - 1);
	}
	cout << ans << endl;
	return 0;
}
