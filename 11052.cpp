#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int N;
	int *arr;
	int *D;
	cin >> N;
	arr = new int[N+1];
	D = new int[N+1];
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	arr[0] = 0;
	D[0] = 0;
	for(int i = 1; i <= N; i++){
		D[i] = 0;
		for(int j = 1; j <= i; j++){
			D[i] = max(D[i], D[i-j] + arr[j]);
		}
	}
	cout << D[N];
	return 0;
}
