//파도반 수열
#include<iostream>
#include<cstdio>
using namespace std;

int N;
long long D[101] = {0, 1, 1, 1, 2, 2, };

int main(){
	int T;
	cin >> T;
    for(int i = 6; i <= 100; i++){
		D[i] = D[i-5] + D[i-1];
	}
	for(int tc = 1; tc <= T; tc++){
		cin >> N;
        printf("%lld\n", D[N]);
	}
	return 0;
}

