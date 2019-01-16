//1.첫째 줄에 컴퓨터 개수
//2.컴퓨터 수는 100이하, 1번부터 차례로 번호가 매겨짐
//3.둘째 줄에 네트워크 상에서 직접 연결되어있는 컴퓨터 쌍의 수가 주어짐
//4.그 수만큼 한줄에 한쌍씩 네트워크 상에 직접 연결되어 있는 컴퓨터 번호 쌍이 주어짐
//그래프 문제(DFS or BFS)
#include<iostream>
using namespace std;

class Virus {
	int num; //컴퓨터 개수
	int net; //연결된 컴퓨터 개수
	int visit[102]; //거쳐갔는지 아닌지 결정, 컴퓨터 개수만큼
	int con[102][102];//연결된 컴퓨터 다 0으로 초기화
	int x, y;
	int cnt;

public:
	void setCom(){
		cin >> num; // num번째 컴퓨터까지 있음
		cin >> net;
		for (int i = 1; i <= num; i++) {//초기화
			for (int j = 1; j <= num ; j++) {
				con[i][j] = 0;
			}
		}

		for (int i = 1; i <= net; i++) {//연결된 컴퓨터
			cin >> x >> y;
			con[x][y] = 1; //연결되어있으면 1로 만듦
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
		for (int i = 2; i <= num; i++) {//1번을 통해서 걸리는거라 1번컴퓨터 제외
			if (visit[i] == 1) {//방문했다->True면 웜바이러스 걸림
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