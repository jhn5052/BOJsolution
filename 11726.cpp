//2xn Ÿ�ϸ�
#include<iostream>
using namespace std;
int tile[10007] = { 0 };

int main() {
	int n;
	cin >> n;//2xnŸ��
	tile[0] = 1;
	tile[1] = 1;
	tile[2] = 2; //�ּ�
//	tile[3] = 3;
//	tile[4] = 5;
//	tile[5] = 8; //���� Ÿ�ϼ� + ���� Ÿ�� ���� ���ؾ���
	for (int i = 3; i <= n; i++) {
		tile[i] = (tile[i - 1] + tile[i - 2]) %10007;
	}
	cout << tile[n] % 10007 << endl;
	return 0;
}