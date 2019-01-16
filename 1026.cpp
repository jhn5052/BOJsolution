#include<iostream>
using namespace std;

class Func {
	int *A;
	int *B;
	int S = 0;
	int n; //배열 개수,최솟값
	int tmp = 0;//임시저장소
public:
	void setArr() {
		cin >> n;
		A = new int[n];
		B = new int[n];
		for (int i = 0; i < n; i++) {//A배열 set -> 재배열 가능
			cin >> A[i];
		}
		for (int i = 0; i < n; i++) {//재배열 해도 상관없음
			cin >> B[i];
		}
	}

	void reArr() {
		for (int i = 0; i < n; i++) { //A배열 정리(내림차순 정리)
			for (int j = 0; j < i; j++) {
				if (A[i] > A[j]) {
					tmp = A[i];
					A[i] = A[j];
					A[j] = tmp;
				}
			}
		}
		for (int i = 0; i < n; i++) { //B배열 정리(오름차순 정리)
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