#include<stdio.h>

int main() {
	long s;
	int i = 1 , k = 1;//����, ����
	int num;
	scanf("%d", &s);
	if (s > 1000000000) { //���� ��Ż
		return 0;
	}

	while(k < s) {
		num = 6 * i; //���� �ȿ� ����ִ� ���� ����
		k = k + num; //������ ���� ����
		i++;//���� ����
	}

	printf("%d", i); //���� �� = �ּ� ������ ��
	return 0;
}