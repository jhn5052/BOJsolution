//상자 한칸에 하나 -> 익은 토마토 영향 ->상하좌우 익게됨
//토마토들이 몇일 후에 다 익게되는지 최소 일수
//상자의 일부 칸에는 토마토 없을 수도

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int visit[1001][1001];
int tom[1001][1001];
int n_x, n_y;//새로운 좌표
int x = 0, y = 0; //현재좌표
int M, N;//상자 크기 M : 가로, N : 세로
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };//상하좌우
queue<pair<int, int> > q;

bool isInside(int x, int y) {
	return (x < N && x >= 0  && y < M && y >= 0);//범위에 있는지
}

void BFS() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			n_x = x + dir[k][0];
			n_y = y + dir[k][1];
			if (isInside(n_x, n_y) && visit[n_x][n_y] == -1 && tom[n_x][n_y] == 0) {
				visit[n_x][n_y] = visit[x][y] + 1;//하루 늘어남
				q.push(make_pair(n_x, n_y));
			}
		}
	}
}

int Date() {
	int day = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			day = max(day, visit[i][j]);
			if (visit[i][j] == -1 && tom[i][j] == 0) {//익지않은 토마토가 있거나 방문 못한곳이 있을때
				return -1;
			}
		}
	}
	return day;
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tom[i][j];//익으면 1, 익지 않은 상태 0, 없으면 -1
			visit[i][j] = -1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tom[i][j] == 1) {
				q.push(make_pair(i, j)); // 익은곳부터 시작
				visit[i][j] = 0;//방문
			}
		}
	}
	BFS();//토마토 익은것부터 나아가야함, day를 하나씩 늘려줘서 최종값 찾기
	cout << Date() << '\n';
	return 0;
}