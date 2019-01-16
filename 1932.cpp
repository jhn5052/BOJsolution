#include<iostream>
#include<algorithm>
using namespace std;
int num[501][501] = { 0, }; //+1, -1�� ���غ��� ����
int MAX[501][501] = { 0, };//�밢�� +1, -1�߿� ���� ���� ū��

int main() {
	int T;
	int result = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> num[i][j];
		}
	}
	MAX[0][0] = num[0][0];

	for (int i = 0; i < T-1; i++) {
		for (int j = 0 ; j <= i; j++) {
			if (MAX[i][j] + num[i + 1][j] > MAX[i + 1][j])
				MAX[i + 1][j] = MAX[i][j] + num[i + 1][j];

			if (MAX[i][j] + num[i + 1][j + 1] > MAX[i + 1][j + 1])
				MAX[i + 1][j + 1] = MAX[i][j] + num[i + 1][j + 1];
		}
	}
	for (int i = 0; i < T; i++) {
		result = max(result, MAX[T - 1][i]);
	}
	cout << result;
	return 0;
}