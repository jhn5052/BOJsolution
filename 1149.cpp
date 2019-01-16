//1149 dynamic programing
#include<iostream>
#include<algorithm>
using namespace std;
int N;//���Ǽ�

class RGB {
	int result;
	int color[1001][3];
	int D[1001][3];//�κй��� �ּڰ�

public:
	void setPrice() {
		cin >> N; //���� ��
		for (int i = 1; i <= N; i++) {
			cin >> color[i][0]; //red
			cin >> color[i][1]; //green
			cin >> color[i][2]; //blue
		}

		for (int i = 0; i < 3; i++) {
			color[0][i] = 0;
			D[0][i] = 0;
		}

	}

	void minResult() {
		for (int i = 1; i <= N; i++) {
			//1. ó���� red�� ��
			//1-1. �̿��� green�̳� blue

			//2. ó���� green�� ��
			//2-1. �̿��� red�� blue
			
			//3. ó���� blue�϶�
			//3-1. �̿��� red�� green
			//(i-1�� ���̴� �� )�� �� ���Ͽ� �ּҰ��� ���ϱ�
			D[i][0] = min(D[i - 1][1], D[i - 1][2]) + color[i][0]; //1
			D[i][1] = min(D[i - 1][0], D[i - 1][2]) + color[i][1]; //2
			D[i][2] = min(D[i - 1][0], D[i - 1][1]) + color[i][2]; //3
		}

		result = min(D[N][0], min(D[N][1], D[N][2]));
	}

	void Print() {
		cout << result;
	}
};

int main() {
	RGB rgb;
	rgb.setPrice();
	rgb.minResult();
	rgb.Print();
	return 0;
}