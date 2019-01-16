#include<iostream>
using namespace std;

int main(){
	int n;
	int a = 1;
	cin >> n;
	for(int i = 1; i <= 2*n-1; i++){//줄
		if(a == 1){
			for(int j = n-i; j > 0; j--){//공백 개수
				cout << " ";
			}
			if(i == n){
				a = 0;
			}
			for(int k = 0; k < 2*i-1; k++){
				cout << "*";
			}
		}
		else{
			for(int j = 0; j < i-n; j++){
				cout << " ";
			}
			int b = 2*n- i;
			for(int k = 0; k < 2*b-1; k++){
				cout << "*";
			}
		}
		cout << "\n";
	}
	return 0;
}



