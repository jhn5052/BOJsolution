#include<iostream>
using namespace std;

int N;
int DP[1001][1001];

int main(){
	cin >> N; 
	for(int i = 0; i <= 9; i++){
		DP[1][i] = 1;
	}

	for(int i = 2; i <= N; i++){
		DP[i][0] = DP[i-1][0];
		for(int j = 1; j <= 9; j++){
			DP[i][j] = (DP[i][j-1] + DP[i-1][j]) % 10007;
		}
	}

	int result = 0;
	for(int i = 0; i <= 9; i++){
		result += DP[N][i];
		result %= 10007;
	}
	cout << result << '\n';
	return 0;
}
