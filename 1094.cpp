#include<iostream>
using namespace std;

int main(){
	int X;
	int t = 64;//합
	int cur = 0;
	int cnt = 0;
	cin >> X;

	while(X != cur){
		if(t > (X-cur)){
			t /= 2;
		}
		else{
			cnt++;
			cur += t;
		}
	}
	cout << cnt;
	return 0;
}


