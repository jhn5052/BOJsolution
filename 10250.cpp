#include<iostream>
using namespace std;

int Num(int H,int W,int N){
	int i = 1;
	int j = 1;
	int n = 1;
	while(1){ //i층 j호
		for(i = 1 ; i <= H ; i++){
			if(n == N){
				if(j < 10){
					cout << i << 0 << j << endl;
				}
				else{
					cout << i << j << endl;
				}
				return 0;
			}
			n++;
		}
		j++;
		if(j > W){
			j = 1;
		}
	}
}

int main(){
	int T;
	int H,W,N;
	cin >> T;
	for(int i = 0 ; i < T ; i++){
		cin >> H >> W >> N;
		Num(H,W,N);
	}
	return 0;
}
