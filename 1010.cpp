//1010 �ٸ�����
//�� �ֺ��� �ٸ� ���� ������ �� -> ����Ʈ
// �� ���ʿ��� N���� ����Ʈ, ���ʿ��� M���� ����Ʈ(N<=M)
//�� ����Ʈ�� �ٸ��� ���� -> �ϴ��� �Լ�
//�ٸ��� ���� ������ �� ���� : N-> M�� ����Ǿ�����, N+1�� M-1�� ����� �� ����
#include<iostream>
using namespace std;
int D[31][31] = { 0 };

int Bridge(int M, int N) {
	if (N == M) {
		return 1;
	}

	else {
		for (int i = 1; i <= M; i++) {//�翷�� �ʱ�ȭ
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