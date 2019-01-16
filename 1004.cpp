#include<iostream>
using namespace std;
int T;

//count
//1. 시작점과 끝점이 원 하나에 들어있는 경우 -> 0번 진입,이탈
//2. 시작점과 끝점이 원 밖에 있는 경우 -> 0번 진입,이탈
//3. 시작점과 끝점중 하나또는 둘다 원안에 들어있는 경우 -> 원의 개수 n만큼 진입,이탈

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
			d = (planetX[i] - startX)*(planetX[i] - startX) + (planetY[i] - startY)*(planetY[i] - startY);//거리로 만들어지는 원
			if (d > (radius[i]*radius[i])) { //행성보다 클 경우
				in1 = 0; //행성 원 밖에 있음
			}
			else {
				in1 = 1; //행성 원 안에 있음
			}
			d = (planetX[i] - endX)*(planetX[i] - endX) + (planetY[i] - endY)*(planetY[i] - endY);
			if (d > (radius[i]*radius[i])) {
				in2 = 0;
			}
			else {
				in2 = 1;
			}

			if (in1 != in2) { //다른 경우 -> 점하나는 행성 안에, 다른 하나는 행성 밖에, 두 점을 이으려면 경계를 지나야함
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