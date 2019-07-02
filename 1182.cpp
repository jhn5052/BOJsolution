#include<iostream>
using namespace std;

int N, S;
int arr[21]; //maximum

int main(){
	//input
	int sum = 0;
	int cnt = 0;
	cin >> N >> S;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}

	for(int i = 1; i < (1<<N); i++){//0일때 제외
		sum = 0;
		for(int j = 0; j < N; j++){
			if(i & (1 << j)){
				sum += arr[j];
			}
		}
		if(sum == S){
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;

}
