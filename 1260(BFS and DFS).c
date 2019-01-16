//<BFS�� DFS> !!!!!
//DFS -> ���� �켱 Ž�� (stack�̿� -> FIFO)
//BFS -> �ʺ� �켱 Ž�� (Queue�̿� -> LIFO)
//cpp <queue> <stack> -> STL��� -> ex) p.queue<pair<x,y>>
//
//Graph��
//1. �湮�� �� �ִ� ������ �������� ��ȣ�� �����ͺ���
//2. ��ȣ�� 1 ~ N ������
//3. ����� ����
//4. DFS����, �״����� BFS������ ��� ���
//5. Queue�� Stack����


#include<stdio.h>

int G[1001][1001] = {0,};
int visited_B[1001];
int visited_D[1001];
int N; //���� ����
int queue[1001];

int BFS(int V) {
	int i;
	int front = 0, rear = 0;
	int w; //���� ����
	for (i = 1; i <= N; i++) {
		visited_B[i] = 0;
	}
	visited_B[V] = 1;
	printf("%d ", V);
	queue[0] = V; //=enqueue
	rear++; //rear���ٰ� ���� �߰�

	while (front < rear) {
		w = queue[front++];//dequeue
		for(i = 1 ; i <= N ; i++) {
			if (G[w][i] == 1 && visited_B[i] == 0) {
				visited_B[i] = 1;
				printf("%d ", i);
				queue[rear] = i; //���� ���� enqueue
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
	int M, V;// ���� ����, Ž�� ���� ��ȣ
	int v,w,i; // ����, ��������
	scanf("%d%d%d", &N, &M, &V);

	for (i = 0; i < M; i++) {
		scanf("%d", &v);
		scanf("%d", &w);
		G[v][w] = 1; //�����
		G[w][v] = 1;
	}
	DFS(V); 
	printf("\n");
	BFS(V);

	return 0;
}