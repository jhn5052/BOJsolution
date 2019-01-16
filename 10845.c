#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node;

typedef struct Queue {
	Node *front;
	Node *rear;
	int count;
}Queue;

void initQueue(Queue *q);
int empty(Queue *q);
void push(Queue *q, int data);
int pop(Queue *q);
int size(Queue *q);
int front(Queue *q);
int back(Queue *q);

int main() {
	int N;
	int i;
	int pushX;
	char ask[6];
	Queue q;
	initQueue(&q);

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%s", ask);
		if (!strcmp(ask, "push")) {
			scanf("%d", &pushX);
			push(&q, pushX);
		}
		else if (!strcmp(ask, "pop")) {
			printf("%d\n",pop(&q));
		}
		else if (!strcmp(ask, "size")) {
			printf("%d\n",size(&q));
		}
		else if (!strcmp(ask, "empty")) {
			printf("%d\n",empty(&q));
		}
		else if (!strcmp(ask, "front")) {
			printf("%d\n",front(&q));
		}
		else if (!strcmp(ask, "back")) {
			printf("%d\n",back(&q));
		}
	}
	return 0;
}


void initQueue(Queue *q){
	q->front = q->rear = NULL;
	q->count = 0;
}

int empty(Queue *q) {
	if (q->count == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(Queue *q, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if (empty(q) == 1) {
		q->front = node;
	}
	else {
		q->rear->next = node;
	}
	q->rear = node;
	q->count++;
}

int pop(Queue *q) {
	Node *node;
	int data;
	if (empty(q) == 1){
		return -1;
	}
	node = q->front;
	data = node->data;
	q->front = node->next;
	free(node);
	q->count--;
	return data;
}

int size(Queue *q) {
	return q->count;
}

int front(Queue *q) {
	if (empty(q) == 1) {
		return -1;
	}
	else {
		return q->front->data;
	}
}

int back(Queue *q) {
	if (empty(q) == 1) {
		return -1;
	}
	else {
		return q->rear->data;
	}
}