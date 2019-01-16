#include<iostream>
#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;
#define INF 987654321
int dir[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
int cave[126][126];
int d[126][126];
int N;

void Dijkstra() {
	typedef pair<int, int> arr;
	queue<pair<int, arr> > q;
	d[0][0] = cave[0][0];//시작점 잃는 루피
	q.push({ d[0][0],arr(0,0) });
	while (!q.empty()) {
		int value = q.front().first;
		int col = q.front().second.first;
		int row = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_col = col + dir[i][0];
			int n_row = row + dir[i][1];
			if (n_col < N && n_col >= 0 && n_row < N && n_row >= 0) {
				if (d[n_col][n_row] > value + cave[n_col][n_row]) {
					d[n_col][n_row] = value + cave[n_col][n_row];
					q.push({ d[n_col][n_row], arr(n_col, n_row) });
				}
			}
		}
	}
}

int main() {
	int testcase = 0;
	while (1) {
		scanf("%d", &N);
		if (N == 0) {
			return 0;
		}
		testcase++;//testcase 증가
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &cave[i][j]);
				d[i][j] = INF;//최대값으로 설정
			}
		}
        Dijkstra();
		printf("Problem %d: %d\n", testcase, d[N - 1][N - 1]);
	}
	return 0;
}
