#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int A;
	int arr[1002];
	int D[1002];
	int M = 0;
	cin >> A;
	for(int i = 1; i <= A; i++){
		cin >> arr[i];
	}
	arr[0] = 0;
	D[0] = 0;
	for(int i = 1; i <= A; i++){
		int min = D[0];
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j]){
				if(min < D[j]){
					min = D[j];
				}
			}
		}
		D[i] = min + 1;
		M = max(M, D[i]);
	}
	cout << M << '\n';
	return 0;
}

