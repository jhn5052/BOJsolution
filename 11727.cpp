//2xn타일링2                                                                      
#include<iostream>
using namespace std;
long long D[1001] = { 0 };
int N;

int main(){
	cin >> N;
	D[0] = 0;
	D[1] = 1;
	D[2] = 3;
	D[3] = 5;
	for(int i = 4; i <= N; i++){
		D[i] = ((D[i-2] * 2) + D[i-1]) % 10007;
	}
	cout << D[N] % 10007 << '\n';
	return 0;
}


