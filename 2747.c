//2747�� �Ǻ���ġ
#include<stdio.h>

int main() {
	int n;//����
	int i;
	int fibo[45];
	scanf("%d", &n);
	
	if (n > 45) {
		return 0;//45 �̻��̸� ����(����)
	}

	fibo[0] = 0;//0��° �Ǻ���ġ �� : 0
	fibo[1] = 1;// 1��° �Ǻ���ġ �� : 1

	for (i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	printf("%d", fibo[n]);
	return 0;
}