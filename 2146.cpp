#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
#define INF 987654321
int N;
int map[101][101];
int visit[101][101] = { 0 };
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };


int range(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= N) {
		return 0;
	}
	return 1;
}

void DFS(int x, int y,int cnt) {
	visit[x][y] = 1;
	map[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int n_x = x + dir[i][1];
		int n_y = y + dir[i][0];
		if (range(n_x, n_y) == 1 && visit[n_x][n_y] == 0 && map[n_x][n_y] == 1){
			DFS(n_x, n_y, cnt);
		}
	}
}

int BFS(int cnt) {
	queue<pair <int, int> > q;
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == cnt) {
				visit[i][j] = 1;
				q.push(make_pair(i, j));
			}
		}
	}

	int result = 0;
	while (q.size()) {
		int size = q.size();
		while (size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dir[i][1];
				int ny = y + dir[i][0];
				if (range(nx, ny) == 1) {
					if (map[nx][ny] != 0 && map[nx][ny] != cnt) {
						return result;
					}
					else if (map[nx][ny] == 0 && visit[nx][ny] == 0) {
						visit[nx][ny] = 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		result++;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	//단지번호 붙이기
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				DFS(i, j, cnt);
				cnt++;
			}
		}
	}

	int ans = INF;
	//단지간에 차이 구하기
	for (int i = 1; i < cnt; i++) {
		ans = min(ans, BFS(i));
	}
	cout << ans << endl;
	return 0;
}
