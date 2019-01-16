#include<iostream>
using namespace std;

//가중치 없는 방향그래프 (i,j)로 가는 경로가 있는지 없는지
//그래프의 인접 행렬이 주어짐.
//i번째 줄의 j번째 숫자가 1인 경우에 i에서 j로 가는 간선이 존재
//0인 경우는 없다. i번째 줄의 i번째 숫잔 항상 0

class Graph {
	int N; //정점의 개수
	int G[101][101];//(i,j) or (i,m)(m,j)->중간 지나쳐서 j로 가는 방법

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