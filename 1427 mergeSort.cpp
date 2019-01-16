#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_SIZE 11
int b[MAX_SIZE];

void Merge(int a[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= high) {
		if (a[i] >= a[j]) {
			b[k] = a[i];
			k++;
			i++;
		}

		else {
			b[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid) {
		b[k++] = a[i++];
	}

	while (j <= high) {
		b[k++] = a[j++];
	}
	k -= 1;
	while (k >= 0) {
		a[low + k] = b[k];
		k--;
	}
}

void MergeSort(int a[], int low, int high)
{
	if (low < high) {
		int m = (high + low) / 2;
		MergeSort(a, low, m);
		MergeSort(a, m + 1, high);
		Merge(a, low, m, high);
	}
}


int main() {
	int num, num_s;
	int i = 0;
	int *a;
	int len = 0;
	cin >> num;
	num_s = num;
	while (num_s != 0) {
		num_s = num_s / 10;
		len++;
	}

	a = new int[len + 1];
	for (int j = 0; j < len; j++) {
		a[j] = num % 10;
		num = num / 10;
	}

	MergeSort(a, 0, len - 1);
	for (int j = 0; j < len; j++) {
		cout << a[j];
	}
	while (1);
	return 0;
}