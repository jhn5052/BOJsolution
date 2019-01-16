#include<iostream>
using namespace std;

int main(){
	int Lyear;
	cin >> Lyear;
	if((Lyear % 4 == 0 && Lyear % 100 != 0) || Lyear % 400 == 0){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
