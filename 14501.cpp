#include<iostream>
#include<algorithm>
using namespace std;
int N;// 퇴사하는 날짜 -1
int DP[16] = { 0 };
int arr[16][2];//정보

int main() {
	int M = 0;//max값 찾기
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0];//상담하는데 소요기간
		cin >> arr[i][1];//금액
		DP[i] = arr[i][1];
	}
	arr[0][0] = 0;//0일
	arr[0][1] = 0;//0원
	for (int i = 2; i <= N; i++) {//i일
		for (int j = 1; j < i; j++) {//i일보다 작으면서 할수 있는 부분 
			if (arr[j][0] <= i - j){//다 더해보기
				DP[i] = max(arr[i][1] + DP[j], DP[i]);//그 중 큰값
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if ((arr[i][0] + i) <= (N + 1)) {//DP값중 가장 큰값
			M = max(DP[i], M);
		}
	}
	cout << M;
	return 0;
}
