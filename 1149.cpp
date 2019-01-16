//1149 dynamic programing
#include<iostream>
#include<algorithm>
using namespace std;
int N;//집의수

class RGB {
	int result;
	int color[1001][3];
	int D[1001][3];//부분문제 최솟값

public:
	void setPrice() {
		cin >> N; //집의 수
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
			//1. 처음이 red일 때
			//1-1. 이웃이 green이나 blue

			//2. 처음이 green일 때
			//2-1. 이웃이 red나 blue
			
			//3. 처음이 blue일때
			//3-1. 이웃이 red나 green
			//(i-1에 쓰이는 색 )둘 중 비교하여 최소값을 구하기
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