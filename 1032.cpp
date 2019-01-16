#include<iostream>
#include<string.h>
using namespace std;

int main() {
	int N;//파일 이름의 개수
	int size = 0;
	char file[51][51];
	int j = 0;
	char ans[51];
	cin >> N;
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < N; i++) {
		cin >> file[i];
	}
	while (file[0][j] != '\0') {
		size++;
		j++;
	}
	for (int i = 0; i < size; i++) {
		ans[i] = file[0][i];
	}
	for (int i = 0; i < N-1; i++) {
		for (j = 0; j < size; j++) {
			if (file[i][j] != file[i + 1][j]) {
				ans[j] = '?';
			}
		}
	}

	for (int i = 0; i < size; i++) {
		cout << ans[i];
	}
	return 0;
}
