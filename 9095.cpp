#include<iostream>
using namespace std;

int main() {
	int a;
	int *cnt;//���� ��Ÿ���� ���
	int T; //testcase
	int combine[11] = { 0 }; //1,2,3����

	cin >> T;
	cnt = new int[T];
	combine[0] = 0; //3�� ������ ��� �ʿ�
	combine[1] = 1; 
	combine[2] = 2;
	combine[3] = 4;//������ �� �ִ� ����� ��;

	for (int i = 0; i < T; i++) {
		cin >> a;
		for (int j = 4; j <= a; j++) {
			combine[j] = combine[j - 3] + combine[j - 2] + combine[j - 1];//�ջ�
		}
		cnt[i] = combine[a];
	}

	for (int i = 0; i < T; i++) {
		cout << cnt[i] << '\n';
	}

	return 0;
}
