#include<stdio.h>

int main() {
	long s;
	int i = 1 , k = 1;//껍질, 범위
	int num;
	scanf("%d", &s);
	if (s > 1000000000) { //조건 이탈
		return 0;
	}

	while(k < s) {
		num = 6 * i; //껍질 안에 들어있는 벌집 개수
		k = k + num; //껍질의 숫자 범위
		i++;//껍질 증가
	}

	printf("%d", i); //껍질 수 = 최소 개수의 방
	return 0;
}