//1699번 제곱수의 합
#include<iostream>
#include<algorithm>
using namespace std;
int N;
int D[100001];
int main(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		D[i] = i;
	}
	for(int i = 2; i <= N; i++){
		for(int j = 2; j*j <= i; j++){
			D[i] = min(D[i], D[i-j*j] + 1);
		}
	}
	cout << D[N] << endl;
	return 0;
}


