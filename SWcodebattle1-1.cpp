#include<iostream>
#include<string.h>
using namespace std;

int main() {
	int T;
	char st[5][16];
	char result[76];
	int a, n = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(result, NULL, sizeof(result));
		for (int j = 0; j < 5; j++) {
			memset(st[j], NULL, sizeof(char) * 16);
		}
		a = 0;
		for (int j = 0; j < 5; j++) {
			cin >> st[j];
			if (n < strlen(st[j])) {
				n = strlen(st[j]);
			}
		}
		for (int j = 0; j < n; j++){
			int k = 0;
			while(k < 5){
				if (st[k][j] == '\0') {
					k++;
				}
				else if (st[k][j] != '\0') {
					result[a] = st[k][j];
					k++;
					a++;
				}
			}
		}
		cout << "#" << i + 1 << " ";
		for (int m = 0; m < a; m++) {
			cout << result[m];
		}
		cout << "\n";
	}
	return 0;
}
