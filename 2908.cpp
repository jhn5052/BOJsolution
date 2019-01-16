#include<iostream>
using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	while(1){
		if( (a%10) > (b%10)){
			while(a > 0){
				cout << a%10;
				a /= 10;
			}
			return 0;
		}
		else if((a%10) < (b%10)){
			while(b>0){
				cout << b%10;
				b /= 10;
			}
			return 0;
		}
		else if((a%10) == (b%10)){
			cout << a % 10;
			a /= 10;
			b /= 10;
		}
	}
	return 0;
}


