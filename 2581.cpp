#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 10001
int arr[MAX] = { 0 };

int MinArr(int M, int N){
	for(int i = M; i <= N; i++){
		if(arr[i] == 0){
			return i;
		}
	}
	return 0;
}



int main(){
	int M, N;
	int sum = 0;
	int a = 0;
	arr[1] = 1;//1은 소수가 아님
	scanf("%d%d",&M,&N);
	for(int i = 2; i <= N; i++){
		if(arr[i] == 0){
			for(int j = 2; i*j <= N; j++){
				if(arr[i*j] == 0){
					arr[i*j] = 1;
				}
			}
		}
	}
	a = MinArr(M, N);
	if(a == 0){
		printf("-1\n");
		return 0;
	}
	else{
		for(int i = M; i <= N; i++){
			if(arr[i] == 0){
				sum += i;
			}
		}
		printf("%d\n%d\n", sum, a); 
	}
	return 0;
}
