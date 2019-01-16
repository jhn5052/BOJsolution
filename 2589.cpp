#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

int dir[4][2] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };//상하좌우
int MAX = 0;//시간, 육지(L)일때만 움직일 수 있음
int visit[51][51] = { 0 };
char map[51][51];
int n_r, n_c;
int col, row;
queue<pair<int, int> > q;

void BFS(int c, int r) {
	q.push(make_pair(c, r));
	while (!q.empty()) {
		c = q.front().first;
		r = q.front().second;
		q.pop();
		for (int t = 0; t < 4; t++) {
			n_c = c + dir[t][0];
			n_r = r + dir[t][1];
			if (n_r > 0 && n_r <= row && n_c > 0 && n_c <= col) {
				if (visit[n_c][n_r] == 0 && map[n_c][n_r] == 'L') {
					visit[n_c][n_r] = visit[c][r] + 1;
					q.push(make_pair(n_c, n_r));
					MAX = max(MAX, visit[n_c][n_r]);
				}
			}
		}
	}
}

int main() {
	cin >> col >> row;
	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			if (map[i][j] == 'L') {
				BFS(i, j);
				memset(visit, 0, sizeof(visit));
			}
		}
	}
	cout << MAX << '\n';
	return 0;
}
