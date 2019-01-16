#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int *T;

void merge(int *arr, int low, int mid, int high){
	int l = low;
	int m = mid + 1;
	int k = low;
	while(l <= mid && m <= high){
		if(arr[l] < arr[m]){
			T[k] = arr[l];
			l++;
		}
		else{
			T[k] = arr[m];
			m++;
		}
		k++;
	}
	if(l > mid){
		for(int i = m; i <= high; i++){
			T[k] = arr[i];
			k++;
		}
	}
	else{
		for(int i = l; i <= mid; i++){
			T[k] = arr[i];
			k++;
		}
	}
	for(int i = low; i <= high; i++){
		arr[i] = T[i];
	}
}
int mergeSort(int *arr, int low, int high){
	if(high > low){
		int mid = (low + high)/2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		merge(arr,low, mid, high);
	}
}

int main(){
	int N;
	int *arr;
	scanf("%d",&N);
	arr = (int*)malloc(sizeof(int)*N);
	T = (int*)malloc(sizeof(int)*N);
	for(int i = 0; i < N; i++){
		scanf("%d",&arr[i]);
	}
	mergeSort(arr, 0, N-1);
	for(int i = 0; i < N; i++){
		printf("%d\n",arr[i]);
	}
	return 0;
}
