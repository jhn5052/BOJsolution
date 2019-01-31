#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int T, N;
int map[2][100005];
int DP[2][100005];

int main(){
	cin >> T;
	for(int tc = 1; tc <= T; tc++){
		cin >> N;
		memset(map, 0, sizeof(map));
		memset(DP, 0, sizeof(DP));
		for(int i = 0; i < 2; i++){
			for(int j = 2; j <= N+1; j++){
				cin >> map[i][j];
			}
		}

		for(int i = 2; i <= N+1; i++){
			DP[0][i] = max(DP[0][i-1], max(DP[1][i-1] + map[0][i], 
						DP[1][i-2] + map[0][i]));
			DP[1][i] = max(DP[1][i-1], max(DP[0][i-1] + map[1][i],
						DP[0][i-2] + map[1][i]);
		}
		
		if(DP[0][N+1] >= DP[1][N+1]){
			cout << DP[0][N+1] << '\n';
		}
		else{
			cout << DP[1][N+1] << '\n';
		}
	}
	return 0;
}

