#include<iostream>
using namespace std;
int N;
int col[16] = { 0, };
int cnt = 0;

int range(int a) {
	for (int k = 0; k < a; k++) {
		int t = col[a] - col[k] > 0 ? col[a] - col[k] : (col[a] - col[k]) * -1;
		if (col[k] == col[a] || a - k == t) {
			return -1;
		}
	}
	return 1;
}

void nQueen(int row) {
	if (row == N-1) {
		cnt++;
		return;
	}
	for (int j = 0; j < N; j++) {
		col[row + 1] = j;
		if (range(row + 1) == 1) {
			nQueen(row + 1);
		}
	}
}


int main() {
	cin >> N;
	if (N >= 15) {
		return -1;
	}
	nQueen(-1);
	cout << cnt << endl;
}
