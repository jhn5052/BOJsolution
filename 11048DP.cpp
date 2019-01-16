//11048 이동하기
#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
int D[1001][1001];
int candy[1001][1001];
int main(){
	cin >> N >> M;
	for(int r = 1; r <= N; r++){
		for(int c = 1; c <= M; c++){
			cin >> candy[r][c];
	 	}
	}
	D[1][1] = candy[1][1];
	for(int r = 1; r <= N; r++){
		for(int c = 1; c <= M; c++){
			int result = max(D[r-1][c], max(D[r][c-1], D[r-1][c-1]));
			D[r][c] = result + candy[r][c];
		}
	}
	cout << D[N][M] << endl;
	return 0;
}
