#include<iostream>
using namespace std;

int main() {
	int n;
	int a[101];
	int check;
	int cnt = 0;//소수 개수
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		check = 0;
		cin >> a[i];
		if (a[i] == 1) {
			check++;
		}
		else if (a[i] >= 2) {
			for (int j = 2; j < a[i]; j++) {
				if (a[i] % j == 0) {
					check++;
				}
			}
		}
		if (check == 0) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}