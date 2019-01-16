#include<iostream>
using namespace std;
int T;

//count
//1. �������� ������ �� �ϳ��� ����ִ� ��� -> 0�� ����,��Ż
//2. �������� ������ �� �ۿ� �ִ� ��� -> 0�� ����,��Ż
//3. �������� ������ �ϳ��Ǵ� �Ѵ� ���ȿ� ����ִ� ��� -> ���� ���� n��ŭ ����,��Ż

class Universe {
	int startX, startY;
	int endX, endY;
	int planetNum; // the number of planet
	int *planetX, *planetY;
	int *radius;
	int d, cnt = 0 , n = 0;
	int *count = new int[T];
	int in1, in2;

public:
	void setPoint() { // input start point and end point
		cin >> startX;
		cin >> startY;
		cin >> endX;
		cin >> endY;
		cin >> planetNum;
		planetX = new int[planetNum];
		planetY = new int[planetNum];
		radius = new int[planetNum];
		for (int i = 0; i < planetNum; i++) {
			cin >> planetX[i];
			cin >> planetY[i];
			cin >> radius[i];
		}
	}

	void Solve() {
		cnt = 0;
		for (int i = 0; i < planetNum; i++) {
			d = (planetX[i] - startX)*(planetX[i] - startX) + (planetY[i] - startY)*(planetY[i] - startY);//�Ÿ��� ��������� ��
			if (d > (radius[i]*radius[i])) { //�༺���� Ŭ ���
				in1 = 0; //�༺ �� �ۿ� ����
			}
			else {
				in1 = 1; //�༺ �� �ȿ� ����
			}
			d = (planetX[i] - endX)*(planetX[i] - endX) + (planetY[i] - endY)*(planetY[i] - endY);
			if (d > (radius[i]*radius[i])) {
				in2 = 0;
			}
			else {
				in2 = 1;
			}

			if (in1 != in2) { //�ٸ� ��� -> ���ϳ��� �༺ �ȿ�, �ٸ� �ϳ��� �༺ �ۿ�, �� ���� �������� ��踦 ��������
				cnt++;
			}
		}
		count[n] = cnt;
		n++;
	}
	
	void printResult(int n) {
		cout << count[n]<<endl;
	}
};

int main() {
	cin >> T;
	Universe uni;
	for (int i = 0; i < T; i++) {
		uni.setPoint();
		uni.Solve();
	}
	for (int i = 0; i < T; i++) {
		uni.printResult(i);
	}
	return 0;
}