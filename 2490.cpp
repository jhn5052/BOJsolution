#include<iostream>
using namespace std;

int main(){
	int sum = 0;
	int a;
	int play[3][4];
	for(int i = 0 ; i < 3; i++){
		sum = 0;
		for(int j = 0; j < 4; j++){
			cin >> a;
			sum += a;
		}
		if(sum == 4){//모
			cout << 'E' << '\n';//등(1) 4개
		}
		else if(sum == 0){//윷
			cout << 'D' << '\n';//배(0) 4개
		}
		else if(sum == 3){//도 등(3)
			cout << 'A' << '\n';
		}
		else if(sum == 2){//개 등(2)
			cout << 'B' << '\n';
		}
		else{//걸
			cout << 'C' << '\n';
		}
	}
	return 0;
}



