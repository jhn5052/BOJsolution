//BFS
//(1,1)�϶� ������ �� �ִ�.
#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

class  matrix {
	int n, m;
	int visit[101][101];//��ȴ����ȵ�ȴ��� Ȯ�� 
	int Matrix[101][101];//�Էµ� ���
	int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };//�����¿�
	int now_x = 0, now_y = 0;//0,0���� ����
	int next_x, next_y;
	queue <pair<int, int> > q; //queue �Լ� ����

public:
	void setMatrix() {
		cin >> n;
		cin >> m;

		for (int i = 0; i < n; i++) { //�Է�
			for (int j = 0; j < m; j++) {
				scanf("%1d",&Matrix[i][j]);
			}
		}

		for (int i = 0; i < n; i++) { //�Է�
			for (int j = 0; j < m; j++) {
				visit[i][j] = 0;
			}
		}
	}
	bool isInside(int x, int y) {
		return (x >= 0 && x < n) && (y >= 0 && y < m);
	}

	void Bfs() {
		q.push(pair<int, int>(now_y, now_x));
		visit[now_y][now_x] = 1;//(now_x,now_y)�� �湮
		while (!q.empty()) {
			now_y = q.front().first;
			now_x = q.front().second;
			q.pop();
			if ((now_y == n-1) && (now_x == m-1)) {
				break;
			}
			for (int i = 0; i < 4; i++) {
				next_y = now_y + dir[i][0];
				next_x = now_x + dir[i][1];
				if (isInside(next_y, next_x) && visit[next_y][next_x] == 0 && Matrix[next_y][next_x] == 1) {
					visit[next_y][next_x] = visit[now_y][now_x] + 1;
					q.push(pair<int, int>(next_y, next_x));//�湮�ؾ��ϴ� �� �ֱ�
				}
			}
		}
		
	}

	//int printMatrix() {
	//	for (int i = 0; i < n; i++) {
	//		for (int j = 0; j < m; j++) {
	//			cout << visit[i][j];
	//		}
	//		cout << endl;
	//	}
	//	return visit[n - 1][m - 1];
	//}

	void result() {
		cout << visit[n - 1][m - 1];
	}
};

int main() {
	matrix matrix;
	matrix.setMatrix();
	matrix.Bfs();
//	matrix.printMatrix();
	matrix.result();
	while (1);
	return 0;
}