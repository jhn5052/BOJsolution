#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int M, N;
	int arr[1000001];
	arr[0] = 1;
	arr[1] = 1;//소수 아님
	scanf("%d%d", &M, &N);
	for(int i = 2; i <= N; i++){
		if(arr[i] == 0){
			for(int j = 2; i*j <= N; j++){
				if(arr[i*j] == 0){
					arr[i*j] = 1;
				}
			}
		}
	}
	for(int i = M; i <= N; i++){
		if(arr[i] != 1){
			printf("%d\n", i);
		}
	}
	return 0;
}


