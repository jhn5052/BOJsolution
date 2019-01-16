#include<iostream>
using namespace std;

int main(){
	int num;
	int *arr;//진짜 약수 개수
	cin >> num; //약수 개수
	arr = new int[num];
	for(int i = 0; i < num; i++){
		cin >> arr[i];
	}

	if(num == 1){
		cout << arr[0] * arr[0]; //약수개수 1개라면 그거의 제곱
	}
	else{//정렬 해준 뒤 제일 앞의 숫자와 가장 뒤의 숫자 곱해주면 약수
		for(int j = 0; j < num-1; j++){
			for(int k = 0; k < num-1; k++){
				if(arr[k] > arr[k+1]){
					int tmp = arr[k];
					arr[k] = arr[k+1];
					arr[k+1] = tmp;
				}
			}
		}
		cout << arr[0] * arr[num-1];
	}
	return 0;
}
