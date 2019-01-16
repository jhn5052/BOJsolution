#include<iostream>
#include<queue>
using namespace std;
int N, M;
int g[1001][1001] = { 0 };
int visit[1001] = { 0 };
queue<int> q;
int u, v;
int cnt = 0;

void BFS(int a) {
	visit[a] = 1;
	while (!q.empty()) {
		int n_u = q.front();//u정점
		q.pop();//u점에 연결된 것 따라가야함
		for (int k = 1; k <= N; k++) {
			if (g[n_u][k] == 1 && visit[k] == 0) {
				visit[k] = 1;
				q.push(k);
			}
		}
	}
}

int main() {
	cin >> N >> M;//정점의 개수, 간선의 개수
	for (int i = 0; i < M; i++) {
		cin >> u >> v;//간선의 양 끝점
		g[u][v] = 1;
		g[v][u] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++){
			if (visit[i] == 0 && g[i][j] == 1) {
				q.push(i);
				BFS(i);
				cnt++;
			}
		}
	}
	for (int i = 1; i <= N; i++) {//연결아예안된 점들 추가
		bool a = false;
		for (int j = 1; j <= N; j++) {
			if (g[i][j] == 1) {
				a = true;
			}
		}
		if (a == false) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
