#include<iostream>
using namespace std;
int M, N, K;
int nx, ny;
int arr[100][100] = { 0 };
bool visit[100][100] = { false }; //영역 구분 = 카운트
int dir[4][2] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };
int q = 0, cnt = 0;//영역개수, 몇개
int len[100] = { 0 };

bool isInside(int y, int x) {
	return (y >= 0 && y < M && x >= 0 && x < N);
}

void DFS(int y, int x) {
	visit[y][x] = true;
	cnt++;
	for (int j = 0; j < 4; j++) {
		ny = y + dir[j][0];
		nx = x + dir[j][1];
		if (isInside(ny, nx) && visit[ny][nx] == false) {
			if (arr[ny][nx] == 1) {
				DFS(ny, nx);
			}
		}
	}
}

int main() {
	cin >> M >> N >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = 1;// 기본 값
		}
	}
	for (int i = 0; i < K; i++) {
		int x, y, a, b;//(x,y)왼쪽 아래 꼭짓점, (a,b)오른쪽 위 꼭짓점
		cin >> x >> y >> a >> b;
		//x와 y이동해서 a와 b가 같아질때까지 true로 만들어줌
		for (int ty = y; ty < b; ty++) {
			for (int tx = x; tx < a; tx++) {
				arr[ty][tx] = 0;//벽있는 부분 0으로 만들기
			}
		}
	}
	for (int ty = 0; ty < M; ty++) {
		for (int tx = 0; tx < N; tx++) {
			if (visit[ty][tx] != true && arr[ty][tx] == 1) {
				DFS(ty, tx);
				len[q] = cnt;
				cnt = 0;
				q++;
			}
		}
	}
	cout << q << '\n';
	for (int i = 0; i < q - 1; i++) {
		for (int j = 0; j < q - 1 - i; j++) {
			if (len[j] > len[j + 1]) {
				int tmp = len[j];
				len[j] = len[j + 1];
				len[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < q; i++) {
		cout << len[i] << ' ';
	}
	return 0;
}
