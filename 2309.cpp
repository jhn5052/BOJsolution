//일곱 난쟁이 -> 아홉난쟁이
//일곱난쟁이의 키의 합이 100
#include<iostream>
using namespace std;

int SUM(int *h) {
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		sum += h[i];
	}
	return sum;
}

int find(int *h) {
	//a가 7되면 끝, b는 a+1 ~ 6까지 계속 왔다갔다
	int sum = SUM(h);
	for (int a = 0; a < 8; a++) {
		for (int b = a + 1; b < 9; b++) {//100이되면 끝
			if (sum - (h[a] + h[b]) == 100) {
				h[a] = 0;
				h[b] = 0;
				return 0;
			}
		}
	}
	return -1;
}

int main() {
	int h[9];//난쟁이들 키
	for (int i = 0; i < 9; i++) {
		cin >> h[i];
	}

	find(h);

	int temp;//sorting
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8 - i; j++) {
			if (h[j] > h[j + 1]) {
				temp = h[j];
				h[j] = h[j + 1];
				h[j + 1] = temp;
			}
		}
	}

	for (int i = 2; i < 9; i++) {
		cout << h[i] << "\n";
	}
	return 0;
}