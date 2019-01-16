#include<iostream>
#include<algorithm>
using namespace std;
int checkN[10] = { 0 };
int checkA[4] = { 0 };//R B Y G
int result = 0;

int main() {
	char c;
	int n, b = 0; // b는 제일 큰 수
	int five = 0;//색 같은것 존재?
	int next = 0; //연속인가?
	int three = 0, four = 0, two1 = 0, two2 = 0;//4개, 3개같을때, 2개같을때
	for (int i = 0; i < 5; i++) {
		cin >> c >> n;
		if (c == 'R') {
			checkA[0]++;
		}
		else if (c == 'B') {
			checkA[1]++;
		}
		else if (c == 'Y') {
			checkA[2]++;
		}
		else if (c == 'G') {
			checkA[3]++;
		}
		checkN[n]++;
		b = max(b, n);//제일 큰 값 찾기
	}
	for (int i = 0; i < 4; i++) {
		if (checkA[i] == 5) {
			five = 1;//색이 다 같음
		}
	}
	for (int i = 1; i < 6; i++) {
		if (checkN[i] && checkN[i + 1] && checkN[i + 2] && checkN[i + 3] && checkN[i + 4]) {
			next = 1;//연속 됨
		}
	}
	for (int i = 1; i <= 9; i++) {
		if (checkN[i] == 2) {
			if (two1 != 0) {//3.2장 카드 같을때,  7. 2장 같을때
				two2 = i;//첫번째 2장
			}
			else {
				two1 = i;//두번째 2장
			}
		}
		else if (checkN[i] == 3) {//카드 5장중에 3장이 같을때(3번)
			three = i;
		}
		else if (checkN[i] == 4) {//카드 4장이 같을때(2번)
			four = i;
		}
	}
	if (five == 1 && next == 1) {//1번
		cout << 900 + b;
		return 0;
	}
	if (five == 1) {//4번
		cout << 600 + b;
		return 0;
	}
	if (next == 1) {//5번
		cout << 500 + b;
		return 0;
	}
	if (four > 0) {//2번
		cout << 800 + four;
		return 0;
	}
	if (three > 0 && two1 != 0) {//3번
		cout << 700 + 10 * three + two1;
		return 0;
	}
	if (three > 0) {//6번
		cout << 400 + three;
		return 0;
	}
	if (two1 != 0 && two2 != 0) {//7번
		int p = max(two1, two2);
		int q = min(two1, two2);
		cout << 300 + 10 * p + q;
		return 0;
	}
	if (two1 != 0) {
		cout << 200 + two1;//8번
		return 0;
	}
	cout << 100 + b;//9번
	return 0;
}
