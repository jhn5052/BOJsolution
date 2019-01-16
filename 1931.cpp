#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int N; //회의의 수

typedef struct Time {
	int start;
	int end;
}Time;
Time t[100001];

bool Case(Time &x, Time &y) {
	if (x.end == y.end) {
		return x.start < y.start;
	}
	else {
		return x.end < y.end;
	}
}

int main() {
	int cnt = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &t[i].start, &t[i].end);
	}
	sort(t, t + N, Case);

	int ans = 0;//끝나는 시간 저장
	for (int i = 0; i < N; i++) {
		if (ans <= t[i].start) {//그 전 회의끝나는 시간이 다음 끝나는 시간보다 작거나 같을때 
			ans = t[i].end;
			cnt++; //회의 하나 추가가능
		}
	}
	printf("%d", cnt);
	return 0;
}
