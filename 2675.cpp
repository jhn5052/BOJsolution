#include<iostream>
using namespace std;

int main() {
	int T;
	int R;//1<=R<=8
	char S[20];
	int k;
	cin >> T;
	for (int i = 0; i < T; i++) {//input testcase
		cin >> R >> S;
		k = 0;
		while (S[k] != '\0') {
			for (int j = 0; j < R; j++) {
				cout << S[k];
			}
			k++;
		}
		cout << "\n";
	}
	return 0;
}