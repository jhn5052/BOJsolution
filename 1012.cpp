#include<iostream>
#include<cstring>
using namespace std;
int dir[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
int arr[51][51] = { 0 };
int visit[51][51] = { 0 };
int M, N, K;
int cnt = 0;
int new_x, new_y;

int isInside(int y, int x) {
	if (x < M && y < N && x >= 0 && y >= 0) {
		return 1;
	}
	else {
		return -1;
	}
}

void DFS(int y, int x) {
	for (int j = 0; j < 4; j++) {//상하좌우
		new_x = x + dir[j][1];
		new_y = y + dir[j][0];
		if (isInside(new_y, new_x) == 1 && visit[new_y][new_x] == 0) {
			if (arr[new_y][new_x] == 1) {
				visit[new_y][new_x] = 1;
				DFS(new_y, new_x);
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		int x, y;
		cnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
		for (int t = 0; t < K; t++) {
			cin >> x >> y;
			arr[y][x] = 1;//배추가 있는 곳
		}
		for (int t = 0; t < N; t++) {
			for (int h = 0; h < M; h++) {
				if (visit[t][h] == 0 && arr[t][h] == 1) {
					visit[t][h] = 1;
					cnt++;//방문 안했는데 배추가 있으면 지렁이추가
					DFS(t, h);
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
