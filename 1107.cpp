//브루트포스
#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;

bool num[10];
int N, M;
int a = 0, b = 0; 
//'a는 리모컨 버튼 누른 수' + 'b는 +,- 누른 수'

int Control(int btn) {//누르는 버튼 확인
	if (btn == 0) {//만약 버튼이 0이면?
		if(num[btn] == true){
			return 0;
		}
		else{
			return 1;
		}
	}
	int len = 0;
	int t = btn;
	int d = 0;
	while (t > 0) {
		d = t % 10;//버튼 누를 수 있는지
		if (num[d] == true) {//누를 수 없으면 :
			return 0;//끝내기
		}
		len++;//버튼 누르는 횟수
		t /= 10;
	}
	return len;//버튼 누르는 횟수
}

int main() {
	int cnt = 0;
	scanf("%d %d", &N, &M);
	memset(num, false, sizeof(num));
	for (int i = 0; i < M; i++) {
		int tmp;
		scanf("%d", &tmp);
		num[tmp] = true;//리모컨 고장난 버튼
	}
	cnt = N - 100;
	if (cnt < 0) {
		cnt *= -1;//음수면 양수로 바꿔주기
	}//+,-만 누른 것

	for (int i = 0; i < 1000000; i++) {
		int btn = i;//누르는 숫자버튼
		a = Control(btn);
		if (a > 0) {
			b = N - btn;//가까운 버튼 까지 가서 +,- 누르기
			if (b < 0) {//음수면 양수로 바꿔주기
				b = b * (-1);
			}
			if (cnt > (a + b)) {
				cnt = a + b;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
