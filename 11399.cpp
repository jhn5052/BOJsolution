#include<iostream>
using namespace std;

int main() {
	int n;
	int *arr;
	int time = 0;
	int sum = 0;
	int temp;

	cin >> n;//ÃÑ °³¼ö
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sum += arr[j];
		}
	}
	cout << sum;
	return 0;

}