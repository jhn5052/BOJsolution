//�ϰ� ������ -> ��ȩ������
//�ϰ��������� Ű�� ���� 100
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
	//a�� 7�Ǹ� ��, b�� a+1 ~ 6���� ��� �Դٰ���
	int sum = SUM(h);
	for (int a = 0; a < 8; a++) {
		for (int b = a + 1; b < 9; b++) {//100�̵Ǹ� ��
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
	int h[9];//�����̵� Ű
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