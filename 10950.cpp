#include<iostream>
using namespace std;

int main() {
	int n;
	int a;
	int b;
	int *sum;
	cin >> n;
	sum = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a < 0 || a > 10 || b < 0 || b > 10) {
			break;
		}
		sum[i] = a + b;
	}

	for (int i = 0; i < n; i++) {
		cout << sum[i] << endl;
	}

	return 0;
}