//OX����
//������ ������ �� �������� ���ӵ� O�� ������ �ȴ�.
#include<iostream>
using namespace std;

int main() {
	int T,L;//�׽�Ʈ ���̽�
	int cnt; //�����ؼ� ���� ���� ����
	int result;
	char a[81];//�־��� ���ڿ�
	int *grade;
	int i, j = 0;
	cin >> T; //�׽�Ʈ ���̽� �Է�
	grade = new int[T]; //���� ����
	L = T; 

	while (T > 0) {
		cin >> a;
		i = 0;
		result = 0;
		cnt = 0;
		while (a[i] != NULL) {
			if (a[i] == 'O') {
				cnt++;
			}
			else if (a[i] == 'X') {
				cnt = 0;
			}
			result += cnt;
			i++;
		}
		grade[j++] = result;
		T--;
	}

	for (int k = 0; k < L; k++) {
		cout << grade[k] << '\n';
	}

	return 0;
}