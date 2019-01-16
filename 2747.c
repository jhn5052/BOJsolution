//2747번 피보나치
#include<stdio.h>

int main() {
	int n;//숫자
	int i;
	int fibo[45];
	scanf("%d", &n);
	
	if (n > 45) {
		return 0;//45 이상이면 끝남(조건)
	}

	fibo[0] = 0;//0번째 피보나치 수 : 0
	fibo[1] = 1;// 1번째 피보나치 수 : 1

	for (i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	printf("%d", fibo[n]);
	return 0;
}