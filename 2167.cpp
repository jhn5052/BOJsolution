#include<iostream>
#include<string.h>
using namespace std;

int N, M, K;
int i, j, x, y;
int arr[301][301];

int main(){
	cin >> N >> M;
	memset(arr, 0, sizeof(arr));

	for(int n = 1; n <= N; n++){
		for(int m = 1; m <= M; m++){
			cin >> arr[n][m];
		}
	}

	cin >> K;
	
	for(int k = 1; k <= K; k++){
		cin >> i >> j >> x >> y;
		int dif_r = x - i;
		int dif_c = y - j;
		if(dif_r == 0 && dif_c == 0){
			cout << arr[i][j] << '\n';
		}
		else{
			int result = 0;
			for(int k = 0; k <= dif_r; k++){
				for(int h = 0; h <= dif_c; h++){
					result += arr[i+k][j+h];
				}
			}
			cout << result << '\n';
		}
	}
	return 0;
}
