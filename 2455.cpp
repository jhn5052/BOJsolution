#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int out;//나간사람
	int in;//들어온사람
	int a = 0;//총 인원 수
	int M = 0;
	for(int i = 0; i < 4; i++){
		cin >> out >> in;
		a -= out;
		a += in;
		M = max(M, a);
	}
	cout << M;
	return 0;
}

