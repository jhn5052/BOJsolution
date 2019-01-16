#include<iostream>
using namespace std;

//����ġ ���� ����׷��� (i,j)�� ���� ��ΰ� �ִ��� ������
//�׷����� ���� ����� �־���.
//i��° ���� j��° ���ڰ� 1�� ��쿡 i���� j�� ���� ������ ����
//0�� ���� ����. i��° ���� i��° ���� �׻� 0

class Graph {
	int N; //������ ����
	int G[101][101];//(i,j) or (i,m)(m,j)->�߰� �����ļ� j�� ���� ���

public:
	void setPoint() {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> G[i][j];
			}
		}
	}

	void Check() { //G[0,1,2,3..][m] - G[m][0,1,2,3..]
		for (int m = 0; m < N; m++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (G[i][m] == 1 && G[m][j] == 1) {
						G[i][j] = 1;
					}
				}
			}
		}
	}

	void Print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << G[i][j] << " ";
			}
			cout << "\n";
		}
	}
};

int main() {
	Graph G;
	G.setPoint();
	G.Check();
	G.Print();
	return 0;
}