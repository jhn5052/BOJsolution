#include<iostream>
using namespace std;
char ch[8][8];//체스(0,0)은 하얀색

int main(){
	int cnt = 0;//하얀칸 위에 말의 수
	for(int i = 0; i < 8; i++){
		cin >> ch[i];//입력
	}

	for(int i = 0; i < 8; i++){//i가 짝수면 하얀칸이 먼저 나옴
		for(int j = 0; j < 8; j++){//i가 짝수->j짝수/ i가 홀수 -> j홀수
			if(i % 2 == 0){
				if(j % 2 == 0){
					if(ch[i][j] == 'F'){
						cnt++;
					}
				}
			}
			else if(i % 2 != 0){
				if(j % 2 != 0){
					if(ch[i][j] == 'F'){
						cnt++;
					}
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
