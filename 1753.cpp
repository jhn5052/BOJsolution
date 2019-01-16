#include<iostream>
#include<queue>//우선순위큐
#include<vector>
#include<cstdio>
using namespace std;
#define INF 987654321
#define MAX_V 20001
#define MAX_E 300001

int V, E, K;
int u, v, w;//정점, 간선개수, 시작정점, 시작, 끝, 가중치
vector<pair<int, int> > arr[MAX_V];//출발노드부터 거리 저장
int d[MAX_V];//정점까지의 최소 길이

void Dijkstra() {
	priority_queue<pair<int, int> > q;//우선순위큐
	q.push({ 0, K });//길이, 시작점
	while (!q.empty()) {
		int now = q.top().second;//현재 노드
		q.pop();
		for (int i = 0; i < arr[now].size(); i++) {
			int cur_val = d[now] + arr[now][i].second;//d[j]값
			int b_val = d[arr[now][i].first];
			if (cur_val < b_val) {
				d[arr[now][i].first] = cur_val;
				q.push({ -1 * cur_val, arr[now][i].first});
			}//-1*cur_val 안하면 시간초과 = visit함수와 같은 처리
		}
	}
}

int main() {
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	for (int i = 1; i <= E; i++) {
		scanf("%d %d %d", &u, &v, &w);//간선, 가중치 입력
		arr[u].push_back({ v,w });//노드에 가중치와 연결된 정점 기록
	}

	for (int i = 1; i <= V; i++) {
		d[i] = INF;//모든 정점 INF
	}
	d[K] = 0;//출발정점만제외
	Dijkstra();

	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", d[i]);
		}
	}
    return 0;
}
