#include<iostream>
using namespace std;

int main() {
	int n,k,j;
	int cnt = 0; // �Ѽ� ����
	int su[3]; //1000���� ���� ���
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i < 100) { //��~���ڸ� ��� �Ѽ�
			cnt = i;
		}
		else if (i == 1000) { //1000->�Ѽ� ���� �ȵ� break
			break;
		}
		else {
			k = i;
			j = 0;
			while (k > 0) {
				//1. 100���� ū ��� ������ �ڸ��� ����� Ȯ��
				su[j] = k % 10; //�������� ����
				k = k / 10;
				j++;
			}
			if (su[1] - su[2] == su[0] - su[1]) {//2. 100���� ū ��� ���� �ڸ����� Ȯ���ؼ� ���������̸� �Ѽ� �ϳ� �߰�
				cnt++;
			}
		}
	}
	cout << cnt; //�Ѽ� ���
	return 0;
}