//0과 1이 각각 몇번 출력 되는지 구하는 프로그램을 작성
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int fibo[41][2] = { 0 };
	int T, n;
	scanf("%d", &T);
	fibo[0][0] = 1;
	fibo[1][1] = 1;
	for (int i = 2; i < 41; i++) {
		fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
		fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
	}
	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		printf("%d %d\n", fibo[n][0], fibo[n][1]);
	}
	return 0;
}