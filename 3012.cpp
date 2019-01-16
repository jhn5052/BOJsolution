#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

#define MAX 100000
int N;
char str[201] = { 0 };
long long D[201][201];
char L[4] = {'(','{','['};
char R[4] = {')','}',']'};
bool over = false;
long long cnt = 0;

//점화식 D[i][j] += D[i][k-1] * D[k+1][j];
int find(int i, int j){
	long long tmp = 0;
	long long result = 0;
	int index = i;
	if(i > j){
		return 1; //곱해야하니까
	}
	if(D[i][j] != -1){//이미 올바른 괄호 문자열 구한 경우
		return D[i][j];//값return
	}
	for(int p = i + 1; p <= j; p+=2){
		for(int q = 0; q < 3; q++){
			if(str[index] == '?' || str[i] == L[q]){
				if(str[p] == '?' || str[p] == R[q]){
					tmp = find(i+1, p-1) * find(p+1, j);
					result += tmp;
					if(result > MAX){
						over = true;
					}
					result %= MAX;
				}
			}
		}
	}
	D[i][j] = result;
	return D[i][j];
}



int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> str[i];
	}
	memset(D, -1, sizeof(D));
	//0으로 하면 올바른괄호문자열개수가 0일경우도 걸리기 때문
	cnt = find(0, N-1);
	if(N % 2 != 0){//홀수면 무조건 0
		cout << "0" << '\n';
	}
	else if(over == true){
		printf("%05lld\n", cnt);
	}
	else{
		cout << cnt << '\n';
	}
	return 0;
}
