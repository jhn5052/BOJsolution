//1010 다리놓기
//강 주변에 다리 짓기 적합한 곳 -> 사이트
// 강 서쪽에는 N개의 사이트, 동쪽에는 M개의 사이트(N<=M)
//두 사이트를 다리로 연결 -> 일대일 함수
//다리는 서로 겹쳐질 수 없음 : N-> M과 연결되었을때, N+1이 M-1과 연결될 수 없음
#include<iostream>
using namespace std;
int D[31][31] = { 0 };

int Bridge(int M, int N) {
	if (N == M) {
		return 1;
	}

	else {
		for (int i = 1; i <= M; i++) {//양옆줄 초기화
			D[i][1] = i;
			D[i][i] = 1;
		}

		for (int i = 3; i <= M; i++) {
			for (int j = 2; j < M; j++) {
				D[i][j] = D[i - 1][j - 1] + D[i -1][j];
			}
		}
		return D[M][N];
	}
}


int main() {
	int T; //testcase
	int N, M;
	int *ans;
	cin >> T;
	ans = new int[T];
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		if (N < 0 && N > M && N > 30 && M < 0) {
			return -1;//error return
		}
		ans[i] = Bridge(M, N);
	}

	for (int j = 0; j < T; j++) {
		cout << ans[j] << '\n';
	}
	return 0;
}