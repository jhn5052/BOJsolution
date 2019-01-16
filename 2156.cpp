//포도주 시식
#include<iostream>
using namespace std;

int main(){
	int n;
	int *w;
	int *D;
	cin >> n;
	w = new int[n+1];
	D = new int[n+1];
	for(int i = 1; i <= n; i++){
		cin >> w[i];
	}
	D[0] = 0;
	D[1] = w[1];
	D[2] = D[1] + w[2];
	for(int i = 3; i <= n; i++){
		int a = D[i-3] + w[i-1] + w[i];
		int b = D[i-1];
		int c = D[i-2] + w[i];
		if(a > b){
			if(a > c){
				D[i] = a;
			}
			else{
				D[i] = c;
			}
		}
		else if(a <= b){
			if(b > c){
				D[i] = b;
			}
			else{
				D[i] = c;
			}
		}
	}
	cout << D[n];
	return 0;
}

