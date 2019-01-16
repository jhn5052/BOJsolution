#include<iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	for(int i = 1; i <= 2*N-1; i++){
		if(i <= N){
			for(int j = 0; j < i; j++){
				cout << '*'; 
			}
			for(int k = 2*N-2*i; k > 0; k--){
				cout << ' ';
			}
			for(int j = 0; j < i; j++){
				cout << '*';
			}
			cout << '\n';
		}
		else{
			for(int j = 2*N-i; j > 0; j--){
				cout << "*";
			}
			for(int k = 2*N - 2*(2*N - i); k > 0; k--){
				cout << " ";
			}
			for(int j = 0; j < 2*N-i; j++){
				cout << "*";
			}
			cout << '\n';
		}
	}
	return 0;
}

		


