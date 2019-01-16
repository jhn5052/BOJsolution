//���� ��ĭ�� �ϳ� -> ���� �丶�� ���� ->�����¿� �ͰԵ�
//�丶����� ���� �Ŀ� �� �ͰԵǴ��� �ּ� �ϼ�
//������ �Ϻ� ĭ���� �丶�� ���� ����

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int visit[1001][1001];
int tom[1001][1001];
int n_x, n_y;//���ο� ��ǥ
int x = 0, y = 0; //������ǥ
int M, N;//���� ũ�� M : ����, N : ����
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };//�����¿�
queue<pair<int, int> > q;

bool isInside(int x, int y) {
	return (x < N && x >= 0  && y < M && y >= 0);//������ �ִ���
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
				visit[n_x][n_y] = visit[x][y] + 1;//�Ϸ� �þ
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
			if (visit[i][j] == -1 && tom[i][j] == 0) {//�������� �丶�䰡 �ְų� �湮 ���Ѱ��� ������
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
			cin >> tom[i][j];//������ 1, ���� ���� ���� 0, ������ -1
			visit[i][j] = -1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tom[i][j] == 1) {
				q.push(make_pair(i, j)); // ���������� ����
				visit[i][j] = 0;//�湮
			}
		}
	}
	BFS();//�丶�� �����ͺ��� ���ư�����, day�� �ϳ��� �÷��༭ ������ ã��
	cout << Date() << '\n';
	return 0;
}