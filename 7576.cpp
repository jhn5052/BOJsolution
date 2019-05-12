#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

int M, N;
int dir[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
int map[1001][1001];
int visit[1001][1001];
int ans = -1;
queue <pair <int, int> > q;

int range(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}

void BFS() {
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];
			if (range(nr, nc) && visit[nr][nc] == -1 && map[nr][nc] == 0) {
				visit[nr][nc] = visit[r][c] + 1;
				q.push(make_pair(nr, nc));
			}
		}
	}
	
}

int main() {
	cin >> M >> N;
	memset(visit, -1, sizeof(visit));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				visit[i][j] = -9;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				//익은 토마토
				visit[i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
	}
	BFS();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == -1) {
				cout << "-1";
				return 0;
			}
			ans = max(ans, visit[i][j]);
		}
	}
	cout << ans << '\n';
	return 0;
}
