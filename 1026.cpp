#include<iostream>
using namespace std;

class Func {
	int *A;
	int *B;
	int S = 0;
	int n; //�迭 ����,�ּڰ�
	int tmp = 0;//�ӽ������
public:
	void setArr() {
		cin >> n;
		A = new int[n];
		B = new int[n];
		for (int i = 0; i < n; i++) {//A�迭 set -> ��迭 ����
			cin >> A[i];
		}
		for (int i = 0; i < n; i++) {//��迭 �ص� �������
			cin >> B[i];
		}
	}

	void reArr() {
		for (int i = 0; i < n; i++) { //A�迭 ����(�������� ����)
			for (int j = 0; j < i; j++) {
				if (A[i] > A[j]) {
					tmp = A[i];
					A[i] = A[j];
					A[j] = tmp;
				}
			}
		}
		for (int i = 0; i < n; i++) { //B�迭 ����(�������� ����)
			for (int j = 0; j < i; j++) {
				if (B[i] < B[j]) {
					tmp = B[i];
					B[i] = B[j];
					B[j] = tmp;
				}
			}
		}
	}

	void Result() {
		for (int i = 0; i < n; i++) {
			S += A[i] * B[i];
		}
		cout << S;
	}
};

int main() {
	Func a;
	a.setArr();
	a.reArr();
	a.Result();
	return 0;
}