#include<iostream>
using namespace std;

int arr[13];
int ans[6];
int k;
int find(int s, int d){
	if(d == 6){
		for(int i = 0; i < 6; i++){
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return 0;
	}
	for(int i = s; i < k; i++){
		ans[d] = arr[i];
		find(i+1, d+1);
	}
}

int main(){
	while(1){
		cin >> k;
		if(k == 0){
			break;
		}
		for(int i = 0; i < k; i++){
			cin >> arr[i];
		}
		find(0,0);
		cout << '\n';
	}
	return 0;
}
