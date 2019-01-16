#include<iostream>
using namespace std;

int main() {
	int N , n;
	cin >> N;
	n = N;
	for (int i = 1; i <= N; i++) {
		for (int k = n - 1; k > 0; k--) {
			cout << " ";
		}
		for (int j = 0; j < 2 * i - 1; j++) {
			cout << "*";
		}
		cout << "\n";
		n--;
	}
	return 0;
}