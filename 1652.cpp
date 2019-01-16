#include<iostream>
using namespace std;

int main(){
	int N;
	int H_cnt = 0, V_cnt = 0;
	int a = 0, b = 0;//a는 연속된 개수, b는 그 자리 카운트 추가 했는지 아닌지
	char fangz[101][101];
	cin >> N;//N크기의 방
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> fangz[i][j];
		}
	} //자리 상태 입력, "." - 비어있는 곳, "X"-> 짐있는 곳

	for(int i = 0; i < N; i++){ //가로
		a = 0; b = 0;
		for(int j = 0; j < N; j++){
			if(fangz[i][j] == '.'){
				a++;
				if(a >= 2 && b == 0){
					H_cnt++;//가로 cnt증가
					b = 1;//초기화
				}
				
			}
			else if(fangz[i][j] == 'X'){
				a = 0;//X만나면 초기화
				b = 0;
			}
		}
	}
	
	for(int j = 0; j < N; j++){
		a = 0; b = 0;
		for(int i = 0; i < N; i++){
			if(fangz[i][j] == '.'){
				a++;
				if(a >= 2 && b == 0){
					V_cnt++;
					b = 1;
				}
			}
			else if(fangz[i][j] == 'X'){
				a = 0;
				b = 0;
			}
		}
	}
	cout << H_cnt << " " << V_cnt;
	return 0;
}
