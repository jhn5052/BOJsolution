#include<iostream>
using namespace std;

int main(){
	long long N;//시험장 개수, 응시자수,총감독관감시,부감독관 감
	cin >> N;
	long long A[1000002];//시험장마다 응시자 수
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	long long B;
	long long C;
	cin >> B >> C;

	long long num = 0; //N개 시험장마다총 감독관 수
	int i = 0;
	while(i < N){//N=2이면 교실 2개, A[0]A[1]
		A[i] -= B;
		num++;//총감독관
		if(A[i] > 0){
			if(A[i] % C != 0){
				num += A[i] / C + 1;
			}
			else{
				num += A[i] / C;
			}
		}
		i++;
	}
	cout << num;
	return 0;
}


