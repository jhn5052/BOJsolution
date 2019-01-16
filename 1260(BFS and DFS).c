//<BFS와 DFS> !!!!!
//DFS -> 깊이 우선 탐색 (stack이용 -> FIFO)
//BFS -> 너비 우선 탐색 (Queue이용 -> LIFO)
//cpp <queue> <stack> -> STL사용 -> ex) p.queue<pair<x,y>>
//
//Graph로
//1. 방문할 수 있는 정점이 여러개면 번호가 작은것부터
//2. 번호는 1 ~ N 번까지
//3. 양방향 간선
//4. DFS먼저, 그다음에 BFS수행한 결과 출력
//5. Queue와 Stack구현


#include<stdio.h>

int G[1001][1001] = {0,};
int visited_B[1001];
int visited_D[1001];
int N; //정점 개수
int queue[1001];

int BFS(int V) {
	int i;
	int front = 0, rear = 0;
	int w; //인접 정점
	for (i = 1; i <= N; i++) {
		visited_B[i] = 0;
	}
	visited_B[V] = 1;
	printf("%d ", V);
	queue[0] = V; //=enqueue
	rear++; //rear에다가 이제 추가

	while (front < rear) {
		w = queue[front++];//dequeue
		for(i = 1 ; i <= N ; i++) {
			if (G[w][i] == 1 && visited_B[i] == 0) {
				visited_B[i] = 1;
				printf("%d ", i);
				queue[rear] = i; //인접 정점 enqueue
				rear++;
			}
		}
	}
	return 0;
}

int dfsCore(int V) {
	int i;
	visited_D[V] = 1;
	printf("%d ", V);
	for (i = 1; i <= N; i++) {
		if (G[V][i] == 1 && visited_D[i] == 0) {
			dfsCore(i);
		}
	}
	return ;
}

int DFS(int V) {
	int i;
	for (i = 1; i <= N; i++) {
		visited_D[i] = 0;
	}
	dfsCore(V);
	return ;
}


int main() {
	int M, V;// 간선 개수, 탐색 시작 번호
	int v,w,i; // 정점, 인접정점
	scanf("%d%d%d", &N, &M, &V);

	for (i = 0; i < M; i++) {
		scanf("%d", &v);
		scanf("%d", &w);
		G[v][w] = 1; //양방향
		G[w][v] = 1;
	}
	DFS(V); 
	printf("\n");
	BFS(V);

	return 0;
}