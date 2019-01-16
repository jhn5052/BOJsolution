//만취한 상범
#include<iostream>
#include<string.h>
using namespace std;
int n;
bool visit[101];
int ans = 0;

int main(){
	int T;
	cin >> T;
	for(int tc = 1; tc <= T; tc++){
		cin >> n;
		result = 0;
		memset(visit, false, sizeof(visit));//false는 다 연것
		for(int i = 2; i <= n; i++){
			for(int j = 1; j*i <= n; j++){
				if(visit[i*j] == false){//열렸으면 닫기
					visit[i*j] = true;
				}
				else if(visit[i*j] == true){//잠겨있으면 연다
					visit[i*j] = false;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			if(visit[i] == false){
				ans += 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

