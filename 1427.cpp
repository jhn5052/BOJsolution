//소트인사이드(quick sort, merge sort)
#include<iostream>
using namespace std;

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int begin, int end) {
	int L, R;
	int pivot = end;
	L = begin;
	R = end;
	while (L < R) {
		while (a[L] >= a[pivot] && L < R) {
			L++;
		}
		while (a[R] <= a[pivot] && R > R) {
			R--;
		}
		if (L < R) {
			swap(&a[L], &a[R]);
		}
	}
	swap(&a[pivot], &a[R]);
	return R;
}

void QuickSort(int a[], int begin, int end) {
	int pivot;
	if (begin < end) {
		pivot = partition(a, begin, end);
		QuickSort(a, begin, pivot-1);
		QuickSort(a, pivot + 1, end);
	}
}

int main() {
	int num,num_s;
	int i = 0;
	int *a;
	int len = 0;
	cin >> num;
	num_s = num;
	while (num_s != 0) {
		num_s = num_s / 10;
		len++;
	}

	a = new int[len+1];
	for(int j = 0 ; j < len ; j++) {
		a[j] = num % 10;
		num = num / 10;
	}

	QuickSort(a, 0, len);
	for (int j = 0; j < len; j++) {
		cout << a[j];
	}
	return 0;
}