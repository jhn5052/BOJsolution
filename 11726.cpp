//2xn 타일링
#include<iostream>
using namespace std;
int tile[10007] = { 0 };

int main() {
	int n;
	cin >> n;//2xn타일
	tile[0] = 1;
	tile[1] = 1;
	tile[2] = 2; //최소
//	tile[3] = 3;
//	tile[4] = 5;
//	tile[5] = 8; //전의 타일수 + 전전 타일 수를 더해야함
	for (int i = 3; i <= n; i++) {
		tile[i] = (tile[i - 1] + tile[i - 2]) %10007;
	}
	cout << tile[n] % 10007 << endl;
	return 0;
}