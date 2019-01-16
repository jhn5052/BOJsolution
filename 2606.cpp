//1.ù° �ٿ� ��ǻ�� ����
//2.��ǻ�� ���� 100����, 1������ ���ʷ� ��ȣ�� �Ű���
//3.��° �ٿ� ��Ʈ��ũ �󿡼� ���� ����Ǿ��ִ� ��ǻ�� ���� ���� �־���
//4.�� ����ŭ ���ٿ� �ѽ־� ��Ʈ��ũ �� ���� ����Ǿ� �ִ� ��ǻ�� ��ȣ ���� �־���
//�׷��� ����(DFS or BFS)
#include<iostream>
using namespace std;

class Virus {
	int num; //��ǻ�� ����
	int net; //����� ��ǻ�� ����
	int visit[102]; //���İ����� �ƴ��� ����, ��ǻ�� ������ŭ
	int con[102][102];//����� ��ǻ�� �� 0���� �ʱ�ȭ
	int x, y;
	int cnt;

public:
	void setCom(){
		cin >> num; // num��° ��ǻ�ͱ��� ����
		cin >> net;
		for (int i = 1; i <= num; i++) {//�ʱ�ȭ
			for (int j = 1; j <= num ; j++) {
				con[i][j] = 0;
			}
		}

		for (int i = 1; i <= net; i++) {//����� ��ǻ��
			cin >> x >> y;
			con[x][y] = 1; //����Ǿ������� 1�� ����
			con[y][x] = 1;
		}
	}

	void dfsCore(int v) {
		visit[v] = 1;
		for (int i = 1; i <= num; i++) {
			if (visit[i] == 0 && con[v][i] == 1) {
				dfsCore(i);
			}
		}
	}

	void DFS(int v) {
		for (int i = 1; i <= num; i++) {
			visit[i] = 0;
		}
		dfsCore(v);
	}

	void Print() {
		cnt = 0;
		for (int i = 2; i <= num; i++) {//1���� ���ؼ� �ɸ��°Ŷ� 1����ǻ�� ����
			if (visit[i] == 1) {//�湮�ߴ�->True�� �����̷��� �ɸ�
				cnt++;
			}
		}
		cout << cnt;
	}
};

int main() {
	Virus V;
	V.setCom();
	V.DFS(1);
	V.Print();
	while (1);
	return 0;
}