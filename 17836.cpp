//17836. 공주님을 구해라!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <limits.h>
using namespace std;

typedef struct info {
	int r, c;
	bool flag;
}info;

int N, M, T;
int map[101][101];
int visited[2][101][101];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
queue<info> q;
int ans = 0;

void BFS() {
	q.push({ 0, 0, false});
	visited[0][0][0] = 0;
	
	while (!q.empty()) {
		int y = q.front().r;
		int x = q.front().c;
		bool b = q.front().flag;
		q.pop();

		if (y == N - 1 && x == M - 1) {
			return;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];
			//1. range out , 무기가 없는데 벽을 만난 경우, 시간이 안되는 경우
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)	continue;
			if (b == false && map[ny][nx] == 1)	continue;
			if (visited[b][y][x] + 1 > T)	break;

			if (visited[b][ny][nx] > visited[b][y][x] + 1) {
				//2. 무기를 만났을 때
				if (map[ny][nx] == 2) {
					q.push({ ny, nx, true });
					visited[1][ny][nx] = visited[b][y][x] + 1;
				}
				//3. 벽일 때
				else if (b == true && map[ny][nx] == 1) {
					q.push({ ny, nx, true });
					visited[b][ny][nx] = visited[b][y][x] + 1;
				}
				//3. 빈칸일때
				else{
					q.push({ ny, nx, b });
					visited[b][ny][nx] = visited[b][y][x] + 1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			visited[0][i][j] = INT_MAX;
			visited[1][i][j] = INT_MAX;
		}
	}
	BFS();
	int ans = min(visited[0][N - 1][M - 1], visited[1][N - 1][M - 1]);
	if (ans > T) {
		cout << "Fail" << '\n';
	}
	else {
		cout << ans << '\n';
	}
	return 0;
}

