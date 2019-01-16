#include<iostream>
#include<stdlib.h>
using namespace std;

int main() {
	int T, N, H;
	int cnt = 0;
	int **train;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cnt = 0;
		cin >> N >> H;
		train = (int**)malloc(sizeof(int*)*N); //동적할당
		for (int i = 0; i < N; i++) {
			train[i] = (int*)malloc(sizeof(int)*2);
		}
		for (int j = 0; j < N; j++) {
			cin >> train[j][0];//차량의 길이
		}
		for (int j = 0; j < N; j++) {
			cin >> train[j][1];//점등 상태
		}

		if (train[0][1] == 0) { //첫번째 칸과 마지막 칸은 항상 불켜져있어야함
			cnt++;
			train[0][1] = 1;
		}

		if (train[N - 1][1] == 0) {
			cnt++;
			train[N-1][1] = 1;
		}

		int k = 0;
		int len = H;
		for(int j = 0; j < N-1; j++){
			if (train[j][0] >= H && train[j][1] == 0) { //터널보다 같거나 긴 차량 항상 불 킴
				train[j][1] = 1;
				cnt++;
			}
			if (train[j][1] == 1) {
				len = H;
				continue;
			}
			if (len >= train[j][0]) { //터널길이가 기차칸보다 클때
				len -= train[j][0]; //터널 길이 - 기차칸 = 남은 기차칸
			}
			else {
				len = H; // 원래 터널길이로 복구
				cnt++; // 불켜야하는 횟수 증가
			}
		}

		for (int k = 0; k < N; k++) {//동적할당 해제
			free(train[k]);
		}
		free(train);
		cout << "#" << i + 1 << " " << cnt << endl;
	}
	return 0;
}
