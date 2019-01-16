#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int D[14][14][17000];//세로, 가로, 켜져있는지 아닌지
int N, M;

class Check{
	public:
		void Set(){
			scanf("%d %d", &N, &M);
			memset(D, -1, sizeof(D));//-1은 꺼져있다
		}

		int bit_Mask(int r, int c, int check){//현재 세로, 가로, 상태
			if(r == N){//세로가 같음
				return check == 0;
			}
			if(c == M){
				return bit_Mask(r+1, 0, check);//끝까지 갔으면 
				//한칸 아래로 이동
			}
			int &tmp = D[r][c][check];
			if(tmp != -1){
				return tmp;
			}

			//2x1
			if(check & (1<<c)){//이미 비트가 체크 되어있을때
				return tmp = bit_Mask(r, c+1, check&~(1<<c));
				//check&~(1<<c) ->xor
			}
			tmp = bit_Mask(r, c+1, check|(1<<c));//비트 더하기
			//2x1일때 옆으로 이동하면서 비트 1 칠하기
			
			//1x2
			if(c <= M-2 && !(check & (2 << c))){
				tmp += bit_Mask(r, c+2, check);//1x2일때 2칸 이동
			}
			return tmp % 9901;
		}
};

int main(){
	int ans = 0;
	Check c;
	c.Set();
	if(N*M % 2 == 0){
		ans = c.bit_Mask(0,0,0);
	}
	else{
		ans = 0;
	}
	printf("%d",ans);
	return 0;
}


