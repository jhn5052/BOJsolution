#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 100001
int A[MAX];
int B;

int binary(int N, int B) {
	int front = 0;
	int rear = N - 1;
	int mid;
	while (rear - front >= 0) {
		mid = (rear + front) / 2;
		if(A[mid] == B){
			printf("1\n");
			return 0;
		}
		else if (A[mid] > B) {
			rear = mid-1;
		}
		else {
			front = mid + 1;
		}
	}
	printf("0\n");
	return 0;
}

int main() {
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	sort(A, A + N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &B);
		binary(N, B);
	}
	return 0;
}
